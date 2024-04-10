#include<bits/stdc++.h>
using namespace std;

const int _ = 1e7 + 7 , P = 998244353; int N , M , K , ivm;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
bool nprm[_]; int prm[_ / 10] , pw[_] , coef[_] , iv[_] , cprm;

void sieve(){
	pw[1] = 1; pw[0] = !K;
	for(int i = 2 ; i <= K ; ++i){
		if(!nprm[i]){prm[++cprm] = i; pw[i] = poww(i , K);}
		for(int j = 1 ; prm[j] * i <= K ; ++j){
			nprm[prm[j] * i] = 1; pw[prm[j] * i] = 1ll * pw[prm[j]] * pw[i] % P;
			if(i % prm[j] == 0) break;
		}
	}
}

int main(){
	cin >> N >> M >> K; sieve(); K = min(N , K);
	iv[1] = 1; for(int i = 2 ; i <= K ; ++i) iv[i] = P - 1ll * (P / i) * iv[P % i] % P;
	coef[K] = 1; ivm = poww(M , P - 2); int bm = N != K;
	for(int i = K - 1 ; ~i ; --i){
		bm = 1ll * bm * (P - ivm) % P * (N - i - 1) % P * iv[K - i] % P;
		coef[i] = (1ll * coef[i + 1] * (P + 1 - ivm) + bm) % P;
	}
	int sum = 0 , tms = 1;
	for(int j = 0 ; j <= K ; ++j){
		sum = (sum + 1ll * tms * pw[j] % P * coef[j]) % P;
		tms = 1ll * tms * ivm % P * (N - j) % P * iv[j + 1] % P;
	}
	cout << sum; return 0;
}