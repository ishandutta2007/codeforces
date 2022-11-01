#include<bits/stdc++.h>
using namespace std;

const int _ = 2003 , MOD = 998244353;
int stir[_][_] , fac[_] , ifac[_] , N , P[_] , Q[_] , s[_] , t[_] , cnt[3] , num , nxt[_] , f[_] , g[_] , h[_]; bool vis[_];
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % MOD; a = a * a % MOD; b >>= 1;} return tms;}
int binom(int a , int b){return 1ll * fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;}

void search(int x){
	int t = x; do t = nxt[t]; while(t != 0 && t != x);
	if(t == x){++num; do vis[t = nxt[t]] = 1; while(t != x);}
}

void init(){
	stir[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= i ; ++j)
			stir[i][j] = (stir[i - 1][j - 1] + (i - 1ll) * stir[i - 1][j]) % MOD;
	fac[0] = 1; for(int i = 1 ; i <= N ; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[N] = poww(fac[N] , MOD - 2); for(int i = N - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % MOD;
}

void calc(int num , int *f){
	for(int i = 0 ; i <= num ; ++i)
		for(int j = i ; j <= num ; ++j)
			f[i] = (f[i] + 1ll * binom(num , j) * stir[j][i] % MOD * fac[cnt[2] + num - j] % MOD * ifac[cnt[2]]) % MOD;
	for(int i = num ; ~i ; --i) for(int j = i + 1 ; j <= num ; ++j) f[i] = (f[i] - 1ll * f[j] * binom(j , i) % MOD + MOD) % MOD;
}

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){cin >> P[i]; if(P[i]) s[P[i]] = i;}
	for(int i = 1 ; i <= N ; ++i){cin >> Q[i]; if(Q[i]) t[Q[i]] = i;}
	for(int i = 1 ; i <= N ; ++i) if(P[i] && Q[i]) nxt[P[i]] = Q[i]; else ++cnt[P[i] ? 0 : (Q[i] ? 1 : 2)];
	for(int i = 1 ; i <= N ; ++i) if(!vis[i]) search(i);
	for(int i = 1 ; i <= N ; ++i)
		if(s[i] && t[i] && !P[t[i]]){
			int p = i; while(nxt[p]) p = nxt[p];
			if(s[p]){--cnt[0]; --cnt[1]; ++cnt[2];}
		}
	init(); calc(cnt[0] , f); calc(cnt[1] , g);
	for(int i = 0 ; i <= cnt[0] ; ++i) for(int j = 0 ; j <= cnt[1] ; ++j) h[i + j] = (h[i + j] + 1ll * f[i] * g[j]) % MOD;
	memset(g , 0 , sizeof(g)); memset(f , 0 , sizeof(f)); for(int i = 0 ; i <= cnt[2] ; ++i) f[i] = stir[cnt[2]][i];
	for(int i = 0 ; i <= cnt[0] + cnt[1] ; ++i) for(int j = 0 ; j <= cnt[2] ; ++j) g[i + j] = (g[i + j] + 1ll * h[i] * f[j]) % MOD;
	for(int i = cnt[0] + cnt[1] + cnt[2] + num ; i >= num ; --i){g[i] = 1ll * g[i - num] * fac[cnt[2]] % MOD; if(num) g[i - num] = 0;}
	for(int i = N ; i ; --i) printf("%d " , g[i]);
	return 0;
}