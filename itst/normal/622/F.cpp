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

#define ll long long
const int MAXN = 1e6 + 7 , MOD = 1e9 + 7;
int jc[MAXN] , inv[MAXN] , pre[MAXN] , suf[MAXN];
int N , K;

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
	jc[0] = pre[0] = suf[K + 3] = 1;
	for(int i = 1 ; i <= K + 2 ; ++i)
		pre[i] = 1ll * pre[i - 1] * (MOD + N - i) % MOD;
	for(int i = K + 2 ; i ; --i)
		suf[i] = 1ll * suf[i + 1] * (MOD + N - i) % MOD;
	for(int i = 1 ; i <= K + 2 ; ++i)
		jc[i] = 1ll * jc[i - 1] * i % MOD;
	inv[K + 2] = poww(jc[K + 2] , MOD - 2);
	for(int i = K + 1 ; i >= 0 ; --i)
		inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> K;
	init();
	int cur = 0 , ans = 0;
	for(int i = 1 ; i <= K + 2 ; ++i){
		cur = (cur + poww(i , K)) % MOD;
		ans = (ans + cur * 1ll * suf[i + 1] % MOD * pre[i - 1] % MOD * inv[i - 1] % MOD * inv[K + 2 - i] % MOD * ((K + 2 - i) & 1 ? -1 : 1) + MOD) % MOD;
	}
	cout << ans;
	return 0;
}