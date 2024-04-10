#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a[3005], b[3005];
int t[3005]; string s, p;

vector<int> zf(string s) {
	int n = s.size();
	vector<int> z(n, 0);
	for (int i=1, l=0, r=0; i<n; i++) {
		if (i < r)
			z[i] = min(r-i, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			z[i]++;
		if (i+z[i] > r)
			r = i+z[i], l=i;
	}
	return z;
}

int occ(string a, string b) {
	auto v = zf(a+b);
	for (int i=a.size(); i<(int)(a.size()+b.size()); i++)
		if (v[i] >= (int)a.size())
			return i - a.size();
	return -1;
}

void no() {
	cout << "NO\n";
	exit(0);
}

void probaj(string s, string p) {
	for (int i=0; i<n; i++) {
		int j = occ(s, a[i]);
		string q = a[i];
		if (j != -1)
			q = a[i].substr(0, j) + p + a[i].substr(j + p.size());
		if (q != b[i])
			no();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	for (int i=0; i<n; i++) {
		if (a[i] == b[i]) {
			t[i] = -1;
			continue;
		}
		int f = -1, l = -1;
		for (int j=0; j<(int)a[i].size(); j++) {
			if (a[i][j] != b[i][j]) {
				if (f == -1)
					f = j;
				l = j;
			}
		}
		t[i] = f;

		l++;
		string s1 = a[i].substr(f, l-f);
		string p1 = b[i].substr(f, l-f);
		if (s == "")
			s = s1, p = p1;
		else if (s != s1 || p != p1)
			no();
	}

	// cerr << "jezgro " << s << ' ' << p << '\n';

	string u, v;
	while (1) {
		bool ok = true;
		char p = 0;
		for (int i=0; i<n; i++) {
			if (t[i] == -1)
				continue;
			if (t[i] - (int)u.size() - 1 < 0) {
				ok = false;
				break;
			}
			char c = a[i][t[i] - (int)u.size() - 1];
			if (!p)
				p = c;
			if (p != c) {
				ok = false;
				break;
			}
		}
		if (ok)
			u += p;
		else
			break;
	}
	
	reverse(u.begin(), u.end());
	// cerr << "leva ekstenzija " << u << '\n';
	// cerr << t[0] << " idk\n";

	while (1) {
		bool ok = true;
		char p = 0;
		for (int i=0; i<n; i++) {
			if (t[i] == -1)
				continue;
			if (t[i] + (int)s.size() + (int)v.size() >= (int)a[i].size()) {
				ok = false;
				break;
			}
			char c = a[i][t[i]+s.size()+v.size()];
			if (!p)
				p = c;
			if (p != c) {
				ok = false;
				break;
			}
		}
		if (ok)
			v += p;
		else
			break;
	}

	// cerr << "desna ekstenzija " << v << '\n';

	s = u + s + v;
	p = u + p + v;
	probaj(s, p);

	cout << "YES\n" << s << '\n' << p << '\n';
}