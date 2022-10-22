#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, m;

long long ipow(int x, int p){
	long long res = 1, piv = x;
	while(p){
		if(p & 1) res = res * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return res;
}
long long fact(int x){
	long long res = 1;
	for(int i=1; i<=x; i++) res = res * i % mod;
	return res;
}

long long bino(int x, int y){
	return fact(x) * ipow(fact(x - y) * fact(y) % mod, mod - 2) % mod;
}

int main(){
	cin >> n >> m;
	cout << bino(n + 2 * m - 1, 2 * m) << endl;
}