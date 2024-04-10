#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int P = 998244353; int upd(int x){return x + (x >> 31 & P);}
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int N , K , C , ans[1 << 16] , tmp[17][16]; vector < int > pot[16]; int all[16][17][16][2];

int fac[17] , ifac[17];

void work(int id){
	static int dp[17][16][2]; memset(dp , 0 , sizeof(dp)); dp[0][0][0] = 1;
	for(auto t : pot[id]){
		static int tmp[17][16][2]; memset(tmp , 0 , sizeof(tmp));
		for(int i = 0 ; i <= K ; ++i)
			for(int j = 0 ; j < 16 ; ++j)
				for(int q = 0 ; q < 2 ; ++q)
					if(dp[i][j][q])
						for(int p = 0 ; p + i <= K ; ++p)
							tmp[i + p][j ^ ((t - p) & 15)][q ^ ((t & 15) < p)] = (tmp[i + p][j ^ ((t - p) & 15)][q ^ ((t & 15) < p)]+ 1ll * dp[i][j][q] * ifac[p]) % P;
		memcpy(dp , tmp , sizeof(dp));
	}
	memcpy(all[id] , dp , sizeof(dp));
}

int dp1[17][16];
void dfs(int x , int val){
	if(x < 4){for(int p = 0 ; p < 16 ; ++p) ans[val ^ p] = tmp[K][p]; return;}
	int dp[17][16]; memcpy(dp , tmp , sizeof(dp)); memset(dp1 , 0 , sizeof(dp1));
	for(int i = 0 ; i <= K ; ++i)
		for(int j = 0 ; j < 16 ; ++j)
			if(tmp[i][j])
				for(int p = 0 ; p + i <= K ; ++p)
					for(int q = 0 ; q < 16 ; ++q)
						dp1[i + p][j ^ q] = (dp1[i + p][j ^ q] + 1ll * tmp[i][j] * all[x][p][q][0]) % P;
	memcpy(tmp , dp1 , sizeof(tmp)); dfs(x - 1 , val); memcpy(tmp , dp , sizeof(tmp)); memset(dp1  , 0 , sizeof(dp1));
	for(int i = 0 ; i <= K ; ++i)
		for(int j = 0 ; j < 16 ; ++j)
			if(tmp[i][j])
				for(int p = 0 ; p + i <= K ; ++p)
					for(int q = 0 ; q < 16 ; ++q)
						dp1[i + p][j ^ q] = (dp1[i + p][j ^ q] + 1ll * tmp[i][j] * all[x][p][q][1]) % P;
	memcpy(tmp , dp1 , sizeof(tmp)); dfs(x - 1 , val ^ ((1 << (x + 1)) - 16)); memcpy(tmp , dp , sizeof(tmp));
}

int main(){
	cin >> N >> K >> C; tmp[0][0] = 1; int xr = 0;
	fac[0] = 1; for(int i = 1 ; i <= K ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[K] = poww(fac[K] , P - 2); for(int i = K - 1; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	for(int i = 1 ; i <= N ; ++i){
		int A; cin >> A; xr ^= A;
		if((A & 15) < K) pot[__builtin_ctz(A - (A & 15))].push_back(A);
		else{
			static int dp[17][16]; memset(dp , 0 , sizeof(dp));
			for(int p = 0 ; p <= K ; ++p)
				for(int q = 0 ; q < 16 ; ++q)
					for(int r = 0 ; r + p <= K ; ++r)
						dp[p + r][q ^ ((A - r) & 15)] = (dp[p + r][q ^ ((A - r) & 15)] + tmp[p][q] * 1ll * ifac[r]) % P;
			memcpy(tmp , dp , sizeof(tmp));
		}
	}
	for(int i = 4 ; i < C ; ++i) work(i);
	dfs(C - 1 , xr >> 4 << 4); int iv = 1ll * fac[K] * poww(poww(N , K) , P - 2) % P;
	for(int i = 0 ; i < (1 << C) ; ++i) printf("%lld " , 1ll * iv * ans[i] % P);
	return 0;
}