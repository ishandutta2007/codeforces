#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 60;

bool lessoreq(vector<int> &a, vector<int> &b) {
	for (int i = N - 1; i >= 0; --i) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;
	}
	return true;
}

int main() {
	ll a, b;
	cin >> a >> b;
	int ans = 0;
	vector<int> aa(N), bb(N), cc(N);
	for (int i = 0; i < N; ++i) {
		aa[i] = a % 2;
		bb[i] = b % 2;
		a /= 2;
		b /= 2;
	}
	for (int sz = 1; sz <= N; ++sz)
		for (int pos = 0; pos < sz - 1; ++pos) {
			for (int i = 0; i < N; ++i) {
				if (i == pos || i >= sz) cc[i] = 0;
				else cc[i] = 1;
			}
			if (lessoreq(aa, cc) && lessoreq(cc, bb)){
				 ++ans;
				 //cout << sz << ' ' << pos << '\n';
			}
		}
	cout << ans << '\n';
}