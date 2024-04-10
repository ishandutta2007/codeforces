#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, m;

long long pow_log(long long k){
	if(k == 0){
		return 1;
	}
	long long b = pow_log(k / 2);
	b = (b * b) % MOD;
	if(k % 2){
		b = (b * 2) % MOD;
	}
	return b;
}

int main(){
	cin >> n;
	m = pow_log(n - 1);
	if(n == 0){
		cout << 1;
		return 0;
	}
	cout << (m * ((m * 2) % MOD + 1) ) % MOD;
	return 0;
}