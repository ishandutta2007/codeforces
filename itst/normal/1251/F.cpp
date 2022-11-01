#include<bits/stdc++.h>
using namespace std;

const int P = 998244353 , G = 3 , _ = 1 << 20; int dir[_] , w[_] , need , invnd;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

void init(int len){
	need = 1; while(need < len) need <<= 1;
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	invnd = poww(need , P - 2); static int L = 1;
	for(int &i = L ; i < need ; i <<= 1){w[i] = 1; int wn = poww(G , P / i / 2); for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % P;}
}

void dft(vector < int > &a , int tp){
	a.resize(need); for(int i = 1 ; i < need ; ++i) if(i < dir[i]) swap(a[i] , a[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = a[j + k] , y = 1ll * a[i + j + k] * w[i + k] % P;
				a[j + k] = x + y >= P ? x + y - P : x + y;
				a[i + j + k] = x < y ? x + P - y : x - y;
			}
	if(tp == -1){reverse(a.begin() + 1 , a.end()); for(auto &t : a) t = 1ll * t * invnd % P;}
}

int fac[_] , ifac[_] , cntb[_] , cntr[_] , ans[_] , N , K , Q;
int binom(int x , int y){return 1ll * fac[x] * ifac[y] % P * ifac[x - y] % P;}

int main(){
	fac[0] = 1; for(int i = 1 ; i <= 3e5 ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[300000] = poww(fac[300000] , P - 2); for(int i = 3e5 - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	
	ios::sync_with_stdio(0); cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){int A; cin >> A; ++cntb[A];} for(int i = 1 ; i <= K ; ++i){int A; cin >> A; ++cntr[A];}

	int cnt1 = 0 , cnt2 = 0;
	for(int i = 1 ; i <= 3e5 ; ++i){
		if(cntr[i]){
			vector < int > F , G; F.resize(cnt1 + 1); G.resize(cnt2 + 1);
			for(int i = 0 ; i <= cnt1 ; ++i) F[i] = binom(cnt1 , i);
			for(int i = 0 ; i <= cnt2 ; ++i) G[i] = 1ll * binom(cnt2 , i) * poww(2 , i) % P;
			init(cnt1 + cnt2 + 1); dft(F , 1); dft(G , 1); for(int j = 0 ; j < need ; ++j) F[j] = 1ll * F[j] * G[j] % P;
			dft(F , -1); for(int j = 0 ; j <= cnt1 + cnt2 ; ++j) ans[i + 1 + j] = (ans[i + 1 + j] + F[j]) % P;
		}
		if(cntb[i] == 1) ++cnt2; else if(cntb[i] >= 2) cnt1 += 2;
	}

	for(cin >> Q ; Q ; --Q){int V; cin >>V; cout << ans[V / 2] << '\n';} return 0;
}