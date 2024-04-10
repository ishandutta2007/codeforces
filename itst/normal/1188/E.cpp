#include<bits/stdc++.h>
using namespace std;

const int _ = 2e6 + 7 , MOD = 998244353;
int fac[_] , ifac[_] , K , cnt[_];
int binom(int a , int b){return 1ll * fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;}
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % MOD; a = a * a % MOD; b >>= 1;} return tms;}

int main(){
	cin >> K; for(int x , i = 1 ; i <= K ; ++i){cin >> x; ++x; while(x <= 1e6 + K){++cnt[x]; x += K;}}
	int bound = 1e6 + K; for(int i = 1 ; i <= bound ; ++i) if((cnt[i] += cnt[i - 1]) > i) bound = i - 1;
	fac[0] = 1; for(int i = 1 ; i <= bound + K ; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[bound + K] = poww(fac[bound + K] , MOD - 2); for(int i = bound + K - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % MOD;
	int sum = 0; for(int i = bound ; i > bound - K && ~i ; --i) sum = (sum + binom(i - cnt[i] + K - 1 , K - 1)) % MOD;
	cout << sum; return 0;
}