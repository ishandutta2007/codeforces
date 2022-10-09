#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[305];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	set<char> s;
	for (int i=0; i<n; i++) {
		s.insert(a[i][i]);
		s.insert(a[n-1-i][i]);
	}
	if (s.size() > 1) {
		cout << "NO\n";
		return 0;
	}
	s.clear();
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (i != j && i + j != n-1)
				s.insert(a[i][j]);
	if (s.size() != 1 || a[0][0] == a[0][1]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}