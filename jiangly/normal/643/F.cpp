#include <bits/stdc++.h>
using namespace std;
vector<unsigned> operator*(const vector<unsigned> &lhs, const vector<unsigned> &rhs) {
	vector<unsigned> result(lhs.size() + rhs.size() - 1);
	for (int i = 0; i < lhs.size(); ++i)
		for (int j = 0; j < rhs.size(); ++j)
			result[i + j] += lhs[i] * rhs[j];
	return result;
}
vector<unsigned> power(vector<unsigned> base, int exp, int n) {
	vector<unsigned> result {1};
	while (exp > 0) {
		if (exp & 1) {
			result = result * base;
			result.resize(n);
		}
		base = base * base;
		base.resize(n);
		exp >>= 1;
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p, q;
	cin >> n >> p >> q;
	p = min(p, n - 1);
	auto c = power({1, 1}, n, p + 1);
	unsigned ans = 0;
	for (int i = 1; i <= q; ++i) {
		unsigned result = 0, pw = 1;
		for (int j = 0; j <= p; ++j) {
			result += c[j] * pw;
			pw *= i;
		}
		ans ^= i * result;
	}
	cout << ans << endl;
	return 0;
}