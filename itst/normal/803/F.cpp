#include<bits/stdc++.h>
#define int long long
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

const int MAXN = 1e5 + 10 , MOD = 1e9 + 7;

bool is[MAXN];
int cnt[MAXN] , prime[MAXN] , mob[MAXN] , N , cntP;

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		++cnt[read()];
	for(int i = 2 ; i <= 1e5 ; ++i){
		if(!is[i]){
			prime[++cntP] = i;
			mob[i] = -1;
		}
		for(int j = 1 ; j <= cntP && prime[j] * i <= 1e5 ; ++j){
			is[prime[j] * i] = 1;
			if(i % prime[j] == 0)
				break;
			mob[prime[j] * i] = mob[i] * -1;
		}
	}
	mob[1] = 1;
	int ans = 0;
	for(int i = 1 ; i <= 1e5 ; ++i){
		int c = 0;
		for(int j = 1 ; j * i <= 1e5 ; ++j)
			c += cnt[j * i];
		ans = (ans + mob[i] * (poww(2 , c) - 1) + MOD) % MOD;
	}
	cout << ans;
	return 0;
}