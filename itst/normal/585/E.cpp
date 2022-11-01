#include<bits/stdc++.h>
using namespace std;

const int _ = 1e7 + 7 , MOD = 1e9 + 7;
int upd(int x){return x + (x >> 31 & MOD);}
int pot[_] , num[_] , prm[_] , mu[_] , pw2[_] , cprm , N , mx; bool nprm[_];

void sieve(){
	for(int i = 2 ; i <= mx ; ++i){
		if(!nprm[i]){prm[++cprm] = i; mu[i] = -1;}
		for(int j = 1 ; prm[j] * i <= mx ; ++j){
			int t = prm[j] * i; nprm[t] = 1;
			if(i % prm[j] == 0) break;
			mu[t] = -mu[i];
		}
	}
}

int main(){
	scanf("%d" , &N); for(int i = 1 , x ; i <= N ; ++i){scanf("%d" , &x); ++pot[x]; mx = max(mx , x);}
	sieve(); pw2[0] = 1; for(int i = 1 ; i <= mx ; ++i) pw2[i] = upd((pw2[i - 1] << 1) - MOD);
	int all = 0 , ans = 0;
	for(int i = mx ; i > 1 ; --i){
		int sum = 0; for(int j = i ; j <= mx ; j += i) sum = upd(sum + pot[j]);
		sum = upd(upd((pw2[sum] - 1) * -1 * mu[i] - MOD)); all = upd(all + sum - MOD);
		for(int j = i ; j <= mx ; j += i) num[j] = upd(num[j] - sum);
	}
	for(int i = 1 ; i <= mx ; ++i) ans = (ans + 1ll * pot[i] * (all + num[i])) % MOD;
	cout << ans; return 0;
}