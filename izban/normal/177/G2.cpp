#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

const int maxn = 1 << 17;
const int inf = 2e8 + 10;
const int mod = 1000000007;

ll n;
int k;
string s, a, b;

struct matrix {
	int a[4][4];
	
	matrix() {
		memset(a, 0, sizeof(a));
	}

	matrix operator* (const matrix &m) {
		matrix res;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <  4; j++) {
				for (int k = 0; k < 4; k++) {
					res.a[i][j] = (res.a[i][j] + 1LL * a[i][k] * m.a[k][j]) % mod;
				}
			}
		}
		return res;
	}
};

int calc(string s, string p, int x = -1) {
	string a = p + "#" + s;
	if (x != -1) x += p.length() + 1;
	int n = a.length();
	vector<int> z(n);

	int ans = 0;
	int l = 0, r = -1;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < n && a[z[i]] == a[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;

		if ((x == -1 || i < x && i + z[i] - 1 >= x) && z[i] == p.size()) ans++; 
	}
	return ans;
}

matrix bin(matrix x, ll y) {
	if (y == 1) return x;
	matrix res = bin(x, y / 2);
	res = res * res;
	if (y & 1) res = res * x;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> s;
		a = "a"; b = "b";
		int j = 1;
		while (a.length() < s.length()) {
			string c = b + a;
			a = b;
			b = c;
			j++;
		}
		if (n < j) {
			cout << 0 << endl;
			continue;
		}
		vector<int> ans(min(n + 1, (ll)j + 2));
		ans[j] = calc(a, s);
		if (j + 1 <= n) ans[j + 1] = calc(b, s);
		int cross[2], cur = 0;
		cross[0] = calc(b + a, s, b.length());
		cross[1] = calc(b + a + b, s, b.length() + a.length());

		if (n <= j + 1) {
			cout << ans[n] << endl;
			continue;
		}

		matrix a;
		a.a[0][0] = ans[j];
		a.a[0][1] = ans[j + 1];
		a.a[0][2] = cross[0];
		a.a[0][3] = cross[1];

		matrix b;
		b.a[1][0] = 1;
		b.a[0][1] = 1;
		b.a[1][1] = 1;
		b.a[2][1] = 1;
		b.a[3][2] = 1;
		b.a[2][3] = 1;

		matrix res;
		res = a * bin(b, n - j - 1);
		cout << res.a[0][1] << endl;

		/*j += 2;
		while (j <= n) {
			ans[j] = (ans[j - 1] + ans[j - 2] + cross[cur]) % mod;
			cur ^= 1;
			j++;
		}*/
	}

	return 0;
}