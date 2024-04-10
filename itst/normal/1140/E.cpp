#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<cmath>
#include<random>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c) && c != EOF){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    if(c == EOF)
        exit(0);
    while(isdigit(c)){
	a = a * 10 + c - 48;
        c = getchar();
    }
    return f ? -a : a;
}

const int MAXN = 2e5 + 7 , MOD = 998244353;
int dp[MAXN][2] , arr[MAXN] , N , K;

inline int poww(int a , int b){
    int times = 1;
    while(b){
	if(b & 1) times = times * a % MOD;
	a = a * a % MOD;
	b >>= 1;
    }
    return times;
}

signed main(){
    N = read(); K = read();
    for(int i = 1 ; i <= N ; ++i)
	arr[i] = read();
    vector < int > ind;
    ind.clear();
    for(int i = 1 ; i <= N ; i += 2)
	if(arr[i] != -1)
	    ind.push_back((i + 1) >> 1);
    int times1 , times2;
    if(!ind.empty()){
	dp[0][0] = 1;
	int pos = 0;
	for(int i = 1 ; pos < ind.size() ; ++i)
	    if(ind[pos] == i){
		dp[i][0] = dp[i - 1][0];
		if(++pos < ind.size() && arr[ind[pos] * 2 - 1] == arr[ind[pos - 1] * 2 - 1])
		    swap(dp[i][0] , dp[i][1]);
	    }
	    else{
		if(i == 1){
		    dp[i][0] = K - 1; dp[i][1] = 1;
		}
		else{
		    dp[i][0] = (dp[i - 1][0] * (K - 2) + dp[i - 1][1] * (K - 1)) % MOD;
		    dp[i][1] = dp[i - 1][0];
		}
	    }
	--pos;
	times1 = poww(K - 1 , (N + 1) / 2 - ind[pos]) * (dp[ind[pos]][0] + dp[ind[pos]][1]) % MOD;
    }
    else
	times1 = K * poww(K - 1 , (N + 1) / 2 - 1) % MOD;
    ind.clear();
    for(int i = 2 ; i <= N ; i += 2)
	if(arr[i] != -1)
	    ind.push_back(i >> 1);
    if(!ind.empty()){
	memset(dp , 0 , sizeof(dp));
	dp[0][0] = 1;
	int pos = 0;
	for(int i = 1 ; pos < ind.size() ; ++i)
	    if(ind[pos] == i){
		dp[i][0] = dp[i - 1][0];
		if(++pos < ind.size() && arr[ind[pos] * 2] == arr[ind[pos - 1] * 2])
		    swap(dp[i][0] , dp[i][1]);
	    }
	    else{
		if(i == 1){
		    dp[i][0] = K - 1; dp[i][1] = 1;
		}
		else{
		    dp[i][0] = (dp[i - 1][0] * (K - 2) + dp[i - 1][1] * (K - 1)) % MOD;
		    dp[i][1] = dp[i - 1][0];
		}
	    }
	--pos;
	times2 = poww(K - 1 , N / 2 - ind[pos]) * (dp[ind[pos]][0] + dp[ind[pos]][1]) % MOD;
    }
    else
	times2 = K * poww(K - 1 , N / 2 - 1) % MOD;
    cout << times1 * times2 % MOD;
    return 0;
}