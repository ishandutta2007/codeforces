#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[2005], b[2005], f[2005], s;
int n;
int r[2005], c[2005];

void fr(int i) {
	for (int j=0; j<n; j++)
		a[i][j] ^= s[j];
	r[i] ^= 1;
}

void fc(int j) {
	for (int i=0; i<n; i++)
		a[i][j] ^= s[i];
	c[j] ^= 1;
}

void no() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++) {
		cin >> s;
		for (int j=0; j<n; j++) {
			a[i][j] ^= s[j];
		}
	}
	cin >> s;
	for (int i=0; i<n; i++)
		s[i] -= '0';

	for (int i=0; i<n; i++) {
		if (!s[i]) {
			bool ok0 = true, ok1 = true;
			for (int j=0; j<n; j++) {
				ok0 &= a[i][j] == 0;
				ok1 &= a[i][j] == s[j];
			}
			if (!ok0 && !ok1)
				no();
			else if (ok1)
				fr(i);
		}
	}

	for (int j=0; j<n; j++) {
		if (!s[j]) {
			bool ok0 = true, ok1 = true;
			for (int i=0; i<n; i++) {
				ok0 &= a[i][j] == 0;
				ok1 &= a[i][j] == s[i];
			}
			if (!ok0 && !ok1)
				no();
			else if (ok1)
				fc(j);
		}
	}

	string first;
	for (int i=0; i<n; i++) {
		if (s[i]) {
			if (first.empty()) {
				first = a[i];
			} else {
				if (a[i] != first)
					fr(i);
			}
		}
	}
	for (int j=0; j<n; j++) {
		if (s[j]) {
			bool ok = true;
			for (int i=0; i<n; i++)
				if (a[i][j])
					ok = false;
			if (!ok)
				fc(j);
		}
	}

	for (int i=0; i<n; i++)
		if (a[i] != string(n, 0))
			no();
	
	vector<string> sol;
	for (int i=0; i<n; i++)
		if (r[i])
			sol.push_back("row " + to_string(i));
	for (int i=0; i<n; i++)
		if (c[i])
			sol.push_back("col " + to_string(i));
	cout << sol.size() << '\n';
	for (string s : sol)
		cout << s << '\n';
}