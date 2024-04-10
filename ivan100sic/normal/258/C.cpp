#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int m = 1'000'000'007;

int pw(int a, int k) {
	if (k == 0)
		return 1 % m;
	if (k == 1)
		return a % m;
	int b = pw(a, k >> 1);
	b = b * 1ll * b % m;
	if (k & 1) {
		b = b * 1ll * a % m;
	}
	return b;
}

int n, c[100005], z[100005], sol;
basic_string<int> e[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}
	for (int i=1; i<=100000; i++) {
		z[i] = z[i-1] + c[i];
		for (int j=i; j<=100000; j+=i)
			e[j] += i;
	}

	for (int d=1; d<=100000; d++) {
		int k = e[d].size();
		vector<int> t(k+1, 0);
		for (int i=0; i<k; i++) {
			t[i] = n - z[e[d][i] - 1];
		}

		int p = 1;
		for (int i=0; i<k; i++) {
			int ex = t[i] - t[i+1];
			if (i < k-1) {
				p = p * 1ll * pw(i+1, ex) % m;
			} else {
				int tmp1 = pw(i+1, ex) % m;
				int tmp2 = pw(i+0, ex) % m;
				int t = tmp1 - tmp2;
				if (t < 0)
					t += m;
				p = p * 1ll * t % m;
			}
		}

		sol = (sol + p) % m;
	}

	cout << sol << '\n';
}