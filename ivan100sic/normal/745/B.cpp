#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	auto z = [&](int x, int y) {
		return s[x][y] == 'X';
	};
	for (int i=0; i<n; i++)
		cin >> s[i];
	string ok = "YES";
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m-1; j++) {
			if (z(i, j) + z(i+1, j) + z(i, j+1) + z(i+1, j+1) == 3)
				ok = "NO";
		}
	}
	cout << ok << '\n';
}