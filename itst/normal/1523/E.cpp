#include<bits/stdc++.h>
using namespace std;

#define int long long
const int P = 1e9 + 7;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int T , N , M , fac[100003] , ifac[100003]; string str;
int binom(int a , int b){return a >= b && b >= 0 ? fac[a] * ifac[b] % P * ifac[a - b] % P : 0;}

signed main(){
	fac[0] = 1; for(int i = 1 ; i <= 1e5 ; ++i) fac[i] = fac[i - 1] * i % P;
	ifac[100000] = poww(fac[100000] , P - 2); for(int i = 1e5 - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	for(cin >> T ; T ; --T){
		cin >> N >> M; int sum = 1 , tms = 1;
		for(int i = 1 ; i <= N ; ++i){
			tms = 1ll * tms * poww(N - i + 1 , P - 2) % P * i % P;
			sum = (sum + tms * binom(N - (M - 1) * (i - 1) , i)) % P;
		}
		cout << sum << endl;
	}
	return 0;
}