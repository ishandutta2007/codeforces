#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;
const int N = 100100;
int add(int a, int b) {
	if (a + b >= MOD) return a + b - MOD;
	return a + b;
}
int sub(int a, int b) {
	if (a - b < 0) return a - b + MOD;
	return a - b;
}
int mul(int a, int b) {return (long long)1 * a * b % MOD;}
int f[N];
void solve() {
	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i < N; ++i) {
		f[i] = add(f[i - 1], f[i - 2]);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	solve();
	cout << mul(2, sub(add(f[n], f[m]), 1));
	return 0;
}