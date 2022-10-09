#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

multiset<char> r[105], c[105];
string s[105];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=0; j<m; j++) {
			r[i].insert(s[i][j]);
			c[j].insert(s[i][j]);
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (r[i].count(s[i][j]) == 1 && c[j].count(s[i][j]) == 1)
				cout << s[i][j];
		}
	}
	cout << '\n';
}