#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s, p;

bool nope[10005][11][22];

void dfs(int i, int x, int y) {
	if (nope[i][x][y + 11])
		return;
	
	if (i == n) {
		cout << "YES\n";
		for (int x : p)
			cout << x << ' ';
		cout << '\n';
		exit(0);
	}

	for (int j=1; j<=10; j++) {
		if (j == x)
			continue;
		if (s[j] == '0')
			continue;
		int sgn = i % 2 ? 1 : -1;
		if (i > 1 && y*(y+sgn*j) >= 0)
			continue;
		p += j;
		dfs(i+1, j, y+sgn*j);
		p.pop_back();
	}

	nope[i][x][y+11] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> n;
	s = string("0") + s;

	dfs(0, 0, 0);
	cout << "NO\n";
}