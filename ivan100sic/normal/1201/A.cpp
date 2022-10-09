#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int f[1005][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<m; j++)
			f[j][s[j] - 'A']++;
	}

	int z = 0;
	for (int i=0; i<m; i++) {
		int x = *max_element(f[i], f[i]+5);
		int y;
		cin >> y;
		z += x*y;
	}
	cout << z << '\n';
}