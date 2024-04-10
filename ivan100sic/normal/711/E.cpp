#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000003;

long long ipow(long long a, long long b, long long mod = MOD){
	long long z = 1;
	for (long long i = 1ll<<60ll; i; i >>= 1ll){
		z = z * z % mod;
		if (i & b){
			z = z * a % mod;
		}
	}
	return z;
}

long long inv(long long a){
	return ipow(a, MOD-2);
}

long long cp2(long long k){
	long long t = 0;
	while (k > 0){
		k /= 2;
		t += k;
	}
	return t;
}

long long fallen(long long start, long long k){
	if (k > MOD) return 0;
	start %= MOD;
	long long z = 1;
	for (int i=1; i<k; i++){
		z = z * (start + MOD - i) % MOD;
	}
	return z;
}

long long N, K;

int main(){
	cin >> N >> K;

	if (N <= 60){
		if ((1ll << N) < K){
			cout << "1 1" << endl;
			return 0;
		}
	}
	
	long long below = ipow(ipow(2, N), K-1) * inv(ipow(2, cp2(K-1))) % MOD;
	long long above = below - fallen(ipow(2, N), K) * inv(ipow(2, cp2(K-1))) % MOD;
	if (above < 0) above += MOD;
	
	cout << above << ' ' << below << endl;

	return 0;
}