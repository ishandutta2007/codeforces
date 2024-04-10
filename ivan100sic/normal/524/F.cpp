#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> scs(const string& s) {
	int n = s.size();
	vector<int> p(n), c(s.begin(), s.end());
	vector<vector<int>> g(max(n, 256));
	for (int i=0; i<n; i++)
		g[c[i]].push_back(i);
	int b = 0;
	for (auto& gr : g) {
		for (int x : gr)
			p[b++] = x;
		gr.clear();
	}
	for (int h=1; h<n; h<<=1) {
		vector<int> p2(n), c2(n);
		for (int j : p) {
			int jp = (j+n-h) % n;
			g[c[jp]].push_back(jp);
		}
		b = 0;
		for (auto& gr : g) {
			for (int x : gr)
				p2[b++] = x;
			gr.clear();
		}
		b = 0;
		c2[p2[0]] = 0;
		for (int i=1; i<n; i++) {
			int x = p2[i];
			int y = p2[i-1];
			if (c[x] == c[y] && c[(x+h)%n] == c[(y+h)%n])
				c2[x] = b;
			else
				c2[x] = ++b;
		}
		swap(c, c2);
		swap(p, p2);
	}
	return p;
}

struct stvar {
	int a, b;

	stvar(int x = 0) : a(x), b(min(0, x)) {}

	stvar(int p, int q) : a(p), b(q) {}

	stvar operator+ (const stvar& o) const {
		return stvar(a+o.a, min(b, a+o.b));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	vector<int> p = scs(s);
	vector<stvar> pref(n+1), suff(n+1);
	for (int i=0; i<n; i++)
		pref[i+1] = pref[i] + stvar(s[i] == '(' ? 1 : -1);
	for (int i=n-1; i>=0; i--)
		suff[i] = stvar(s[i] == '(' ? 1 : -1) + suff[i+1];

	for (int j : p) {
		auto t = suff[j] + pref[j];
		if (t.a < 0) {
			if (t.a == t.b) {
				cout << string(-t.a, '(') << s.substr(j) << s.substr(0, j) << '\n';
				return 0;
			}
		} else {
			if (t.b == 0) {
				cout << s.substr(j) << s.substr(0, j) << string(t.a, ')') << '\n';
				return 0;
			}
		}
	}
}