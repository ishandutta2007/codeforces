#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
int z[100005];

vector<int> zalgo(string s) {
	int n = s.size();
	vector<int> z(n);
	for (int i=1, l=0, r=0; i<n; i++) {
		if (i < r)
			z[i] = min(z[i-l], r-i);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			z[i]++;
		if (i+z[i] > r)
			l = i, r = i+z[i];
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	string srev = s;
	reverse(srev.begin(), srev.end());
	auto q = zalgo(srev + '#' + s);
	q.erase(q.begin(), q.begin() + n + 1);
	vector<int> q2(n+1), p(n);
	for (int i=0; i<n; i++)
		if (q[i])
			q2[i+q[i]] = max(q2[i+q[i]], q[i]);
	for (int i=n-1; i>=0; i--)
		q2[i] = max(q2[i], q2[i+1]-1);
	for (int i=1; i<n; i++) {
		p[i] = p[i-1];
		if (q2[i] > q2[p[i]])
			p[i] = i;
	}
	// manacher
	for (int i=0, l=0, r=0; i<n; i++) {
		if (i < r)
			z[i] = min(z[l+r-i], r-i);
		while (i >= z[i] && i+z[i] < n && s[i-z[i]] == s[i+z[i]])
			z[i]++;
		z[i]--;
		if (i + z[i] > r)
			l = i - z[i], r = i + z[i];
	}

	vector<int> sol;
	int val = 0;
	for (int i=0; i<n; i++) {
		int l = i-z[i], r = i+z[i];
		int w = min(q2[p[l]], n-r-1);
		int nov = r-l+1+w+w;
		if (nov > val) {
			val = nov;
			if (w == 0) {
				sol = {i-z[i]+1, 2*z[i]+1};
			} else {
				sol = {p[l]-q2[p[l]]+1, q2[p[l]], i-z[i]+1, 2*z[i]+1, n-w+1, w};
			}
		}
	}

	cout << sol.size() / 2 << '\n';
	int ii = 1;
	for (int x : sol)
		cout << x << " \n"[ii ^= 1];
}