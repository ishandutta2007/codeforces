#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace fft {

	const int mod = 167772161;
	const int root = 243;
	const int root_1 = 114609789;
	const int root_pw = 1 << 25;

	template<class T>
	T eea(T a, T b, T& x, T& y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
	
		T x1, y1;
		T g = eea(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}

	int inverse(int n) {
		int x, y;
		eea(n, mod, x, y);
		x %= mod;
		if (x < 0)
			x += mod;
		return x;
	}

	void fft(vector<int>& a, bool invert) {
		int n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;

			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1)
				wlen = 1LL * wlen * wlen % mod;

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < len / 2; j++) {
					int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
					a[i+j] = u + v < mod ? u + v : u + v - mod;
					a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
					w = 1LL * w * wlen % mod;
				}
			}
		}

		if (invert) {
			int n_1 = inverse(n);
			for (int& x : a)
				x = 1LL * x * n_1 % mod;
		}
	}
}

string a, b;
int n, m;

bool d[125005][6][6];

int p2(int x) {
	int y = 1;
	while (y < x)
		y <<= 1;
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b;
	n = a.size();
	m = b.size();
	int g = p2(n+m+2);
	reverse(b.begin(), b.end());

	vector<int> u[6], v[6];

	for (int i=0; i<6; i++) {
		u[i].assign(g, 0);
		v[i].assign(g, 0);
	}

	for (char x='a'; x<='f'; x++) {
		for (int i=0; i<n; i++)
			if (a[i] == x)
				u[x-'a'][i] = 1;
		for (int i=0; i<m; i++)
			if (b[i] == x)
				v[x-'a'][i] = 1;
	}

	for (int i=0; i<6; i++) {
		fft::fft(u[i], false);
		fft::fft(v[i], false);
	}

	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			vector<int> p(g);
			for (int k=0; k<g; k++)
				p[k] = u[i][k] * 1ll * v[j][k] % fft::mod;
			fft::fft(p, true);
			for (int k=0; k<n-m+1; k++) {
				d[k][i][j] |= p[k+m-1];
				d[k][j][i] |= p[k+m-1];
			}
		}
	}

	for (int i=0; i<n-m+1; i++) {
		vector<char> vis(6, 0);
		int cc = 0;
		for (int j=0; j<6; j++) {
			if (!vis[j]) {
				cc++;
				vis[j] = 1;
				queue<int> q;
				q.push(j);
				while (q.size()) {
					int k = q.front(); q.pop();
					for (int l=0; l<6; l++)
						if (d[i][k][l] && !vis[l]) {
							q.push(l);
							vis[l] = 1;
						}
				}
			}
		}
		cout << 6-cc << ' ';
	}
	cout << '\n';
}