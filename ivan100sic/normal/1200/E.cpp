#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// hashing? no thanks.

vector<int> kmp(const string& s) {
	int n = s.size();
	vector<int> f(n+1);
	f[0] = -1;
	for (int i=1; i<=n; i++) {
		int r = f[i-1];
		while (r != -1 && s[i-1] != s[r])
			r = f[r];
		f[i] = r+1;
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i=0; i<n; i++)
		cin >> s[i];

	string r = s[0];
	for (int i=1; i<n; i++) {
		string q = r.size() < s[i].size() ? s[i] + r : s[i] + r.substr(r.size() - s[i].size());
		int w = min(r.size(), s[i].size()), x = 0;
		auto f = kmp(q);
		for (int i=f.size()-1; i!=-1; i=f[i])
			if (i <= w) {
				x = i;
				break;
			}
		r += s[i].substr(x);
	}
	cout << r << '\n';
}