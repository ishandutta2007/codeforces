#include<iostream>

using namespace std;

typedef long long llint;

const llint MOD = 1000000007;

llint n, m, k;

llint pot (llint x, llint e) {
	if (e==0) return 1;
	if (e&1) {
		return x*pot(x, e-1)%MOD;
	} else {
		llint t=pot(x, e/2);
		return t*t%MOD;
	}
}

int main () {
	cin >> n >> m >> k;
	if (n%2!=m%2 && k==-1) cout << 0; else cout << pot(pot(2, n-1), m-1);
	return 0;
}