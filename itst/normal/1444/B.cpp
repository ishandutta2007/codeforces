#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int N , M , A[300003] , fac[300003] , ifac[300003];
int binom(int p , int q){return 1ll * fac[p] * ifac[q] % P * ifac[p - q] % P;}

int main(){
	ios::sync_with_stdio(0); cin >> N; N *= 2; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	fac[0] = 1; for(int i= 1 ; i <= N ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N] = poww(fac[N] , P - 2); for(int i = N - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	sort(A + 1 , A + N + 1); int sum1 = 0 , sum2 = 0;
	for(int i = 1 ; i <= N ; ++i) sum1 = (sum1 + (i <= N / 2 ? P - A[i] : A[i])) % P;
	cout << 1ll * sum1 * binom(N , N / 2) % P; return 0;
}