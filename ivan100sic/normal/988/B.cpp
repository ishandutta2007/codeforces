#include <bits/stdc++.h>
using namespace std;

string s[105];
int n;

bool cmp(string a, string b) {
	return a.size() < b.size();
}

bool subs(string p, string s) {
	for (int i=0; i+(int)p.size() <= (int)s.size(); i++) {
		if (s.substr(i, p.size()) == p)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];

	sort(s, s+n, cmp);

	for (int i=1; i<n; i++) {
		if (!subs(s[i-1], s[i]))
			return cout << "NO", 0;
	}
	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}