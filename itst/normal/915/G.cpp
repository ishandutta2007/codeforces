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
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
//This code is written by Itst
using namespace std;

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

#define ll long long
const int MAXN = 2e6 + 3 , MOD = 1e9 + 7;
int powx[MAXN] , prime[MAXN] , mu[MAXN] , cf[MAXN];
bool nprime[MAXN];
int cnt , N , K;

inline int poww(ll a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

void init(){
	for(int i = 1 ; i <= K ; ++i)
		powx[i] = poww(i , N);
	mu[1] = 1;
	for(int i = 2 ; i <= K ; ++i){
		if(!nprime[i]){
			prime[++cnt] = i;
			mu[i] = -1;
		}
		for(int j = 1 ; prime[j] * i <= K ; ++j){
			nprime[prime[j] * i] = 1;
			if(i % prime[j] == 0)
				break;
			mu[prime[j] * i] = mu[i] * -1;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	K = read();
	init();
	for(int i = 1 ; i <= K ; ++i)
		for(int j = 1 ; j * i <= K ; ++j)
			(cf[j * i] += mu[i] * (powx[j] - powx[j - 1] + MOD) % MOD) %= MOD;
	int ans = 0;
	for(int i = 1 ; i <= K ; ++i){
		cf[i] = (0ll + MOD + cf[i] + cf[i - 1]) % MOD;
		ans = (ans + (cf[i] ^ i)) % MOD;
	}
	cout << ans;
	return 0;
}