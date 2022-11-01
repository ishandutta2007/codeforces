#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int MOD = 1e9 + 7 , _ = 1e6 + 7;
int dp[2][_] , arr[_] , id[_] , N , L , K , ans;
	
signed main(){
	N = read(); L = read(); K = read(); ans = L % MOD;
	for(int i = 0 ; i < N ; ++i) arr[id[i] = i] = read();
	sort(id , id + N , [&](int p , int q){return arr[p] < arr[q];});
	for(int i = 0 ; i < N ; ++i) dp[0][i] = 1;
	int now = 0;
	for(int i = 2 ; i <= K ; ++i){
	    now ^= 1; int pos = 0 , sum = 0;
		for(int j = 0 ; j < N ; ++j){
			while(pos < N && arr[id[pos]] == arr[id[j]]) sum = (sum + dp[now ^ 1][pos++]) % MOD;
			dp[now][j] = sum; ans = (ans + max(L / N - i + 1 + (L % N > id[j]) , 0ll) % MOD * sum) % MOD;
		}
	}
	cout << ans; return 0;
}