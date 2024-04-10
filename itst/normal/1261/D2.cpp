#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , P = 998244353;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
vector < int > qry; int N , K , tms = 1 , fac[_] , ifac[_];

int main(){
	ios::sync_with_stdio(0); cin >> N >> K; int x; cin >> x; qry.push_back(x);
	fac[0] = 1; for(int i = 1 ; i <= N ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N] = poww(fac[N] , P - 2); for(int i = N - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	for(int i = 2 ; i <= N ; ++i){int t; cin >> t; if(qry.back() == t) tms = 1ll * tms * K % P; else qry.push_back(t);}
	if(qry.size() == 1){cout << 0; return 0;}
	while(qry.front() == qry.back()){tms = 1ll * tms * K % P; qry.pop_back();}
	int lft = 0;
	for(int i = 0 ; 2 * i <= qry.size() ; ++i){
		lft = (lft + 1ll * fac[qry.size()] * ifac[i] % P * ifac[i] % P * ifac[qry.size() - 2 * i] % P * poww(K - 2 , qry.size() - 2 * i)) % P;
	}
	cout << 1ll * tms * (poww(K , qry.size()) - lft + P) % P * (P + 1) / 2 % P; return 0;
}