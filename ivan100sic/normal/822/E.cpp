#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> scs(const string& s) {
	int n = s.size();
	vector<int> c(s.begin(), s.end()), p(n);
	vector<vector<int>> g(max(256, n));
	for (int i=0; i<n; i++)
		g[c[i]].push_back(i);
	int b = 0;
	for (auto& gr : g) {
		for (int x : gr)
			p[b++] = x;
		gr.clear();
	}
	for (int h=1; h<n; h<<=1) {
		for (int j : p) {
			int jp = (j+n-h) % n;
			g[c[jp]].push_back(jp);
		}
		vector<int> p2(n), c2(n);
		b = 0;
		for (auto& gr : g) {
			for (int x : gr)
				p2[b++] = x;
			gr.clear();
		}
		c2[p2[0]] = 0;
		b = 0;
		for (int i=1; i<n; i++) {
			int y = p2[i];
			int x = p2[i-1];
			if (c[x] == c[y] && c[(x+h)%n] == c[(y+h)%n]) {
				c2[y] = b;
			} else {
				c2[y] = ++b;
			}
		}
		swap(c, c2);
		swap(p, p2);
	}
	return p;
}

vector<int> kasai(const string& s, const vector<int>& p, vector<int>& r) {
	int n = s.size(), k = 0;
	vector<int> q(n-1);
	r.resize(n);
	for (int i=0; i<n; i++)
		r[p[i]] = i;
	for (int i=0; i<n; i++) {
		if (r[i] != n-1) {
			int j = p[r[i]+1];
			while (i+k < n && j+k < n && s[i+k] == s[j+k])
				k++;
			q[r[i]] = k;
			k = max(0, k-1);
		} else {
			k = 0;
		}
	}
	return q;
}

struct lcpquery {
	int n, u, v;
	string s;
	vector<int> p, q, r, l2;

	vector<vector<int>> d;

	void make_sparse() {
		d.resize(18, vector<int>(n-1));
		l2.resize(n-1);
		for (int j=0; j<n-1; j++) {
			d[0][j] = q[j];
			if (j > 1)
				l2[j] = l2[j >> 1] + 1;
			if (j < 10)
				cerr << j << ' ' << l2[j] << '\n';
		}
		for (int i=1, h=1; i<18; i++, h<<=1) {
			for (int j=0; j<n-1; j++) {
				d[i][j] = d[i-1][j];
				if (j + h < n-1)
					d[i][j] = min(d[i][j], d[i-1][j+h]);			
			}
		}
	}

	lcpquery(const string& a, const string& b) {
		s = a + '$' + b + '\0';
		n = s.size();
		u = a.size();
		v = b.size();

		p = scs(s);
		q = kasai(s, p, r);
		make_sparse();
	}

	int ask(int i, int j) {
		i = r[i];
		j = r[j+u+1];
		if (i > j)
			swap(i, j);
		int k = l2[j-i];
		return min(d[k][i], d[k][j-(1<<k)]);
	}
};

int n, m, k;
string s, p;

int dp[100005][33];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> m >> p >> k;

	memset(dp, 0xff, sizeof(dp));
	dp[0][0] = 0;

	lcpquery q(s, p);
	for (int i=0; i<n; i++) {
		for (int x=0; x<=k; x++) {
			mx(dp[i+1][x], dp[i][x]);
			if (dp[i][x] != m && dp[i][x] != -1) {
				int l = q.ask(i, dp[i][x]);
				mx(dp[i+l][x+1], dp[i][x] + l);
			}
		}
	}

	int h = 0;
	for (int x=0; x<=k; x++)
		h = max(h, dp[n][x]);
	cout << (h == m ? "YES\n" : "NO\n");
}