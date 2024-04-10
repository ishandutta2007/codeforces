#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define pii pair < int , int >
const int _ = 1e7 , P = 1e9 + 7; int T , N , fac[_] , ifac[_];
int upd(int x){return x + (x >> 31 & P);}
pii operator *(pii p , pii q){
	int v2 = 1ll * p.first * q.first % P , v1 = (1ll *p.first * q.second + 1ll * p.second * q.first) % P,
		v0 = 1ll * p.second * q.second % P;
	return pii((v1 - v2 + P) % P , (v0 - v2 + P) % P);
}
pii operator *(pii p , int q){return pii(1ll * p.first * q % P , 1ll * p.second * q % P);}
pii operator +(pii p , pii q){return pii(upd(p.first + q.first - P) , upd(p.second + q.second - P));}
pii operator -(pii p , pii q){return pii(upd(p.first - q.first) , upd(p.second - q.second));}
int poww(long long a , int b , int tms){while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

int binom(int p , int q){return 1ll * fac[p] * ifac[q] % P * ifac[p - q] % P;}
struct dat{
	pii ans[3000003];
	void init(pii v){
		pii iv = !v.first ? pii(0 , 1) : (v.first == 1 ? pii(P - 1 , P - 1) : pii(1 , 0)); ans[3 * N] = pii(0 , 1);
		for(int i = 3 * N - 1 ; i ; --i)
			ans[i] = pii(0 , binom(3* N + 1 , i + 1)) - ans[i + 1] + iv * ans[i + 1];
	}
}Base[3];

int main(){
	ios::sync_with_stdio(0); N = read(); fac[0] = 1;
	for(int i = 1 ; i <= 3 * N + 1 ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[3 * N + 1] = poww(fac[3 * N + 1] , P - 2 , 1);
	for(int i = 3 * N ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	Base[0].init(pii(0 , 1)); Base[1].init(pii(1 , 0)); Base[2].init(pii(P - 1 , P - 1));
	for(T = read() ; T ; --T){
		int v = read();
		cout << ((Base[0].ans[v] + Base[1].ans[v] + Base[2].ans[v]) * poww(3 , P - 2 , 1)).second << '\n';
	}
	return 0;
}