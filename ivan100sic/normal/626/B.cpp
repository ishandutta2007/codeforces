#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool vis[205][205][205];

void solve(int x, int y, int z) {
	if (vis[x][y][z])
		return;
	vis[x][y][z] = 1;
	if (x && y)
		solve(x-1, y-1, z+1);
	if (x && z)
		solve(x-1, y+1, z-1);
	if (y && z)
		solve(x+1, y-1, z-1);
	if (x >= 2)
		solve(x-1, y, z);
	if (y >= 2)
		solve(x, y-1, z);
	if (z >= 2)
		solve(x, y, z-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = count(s.begin(), s.end(), 'B');	
	int b = count(s.begin(), s.end(), 'G');	
	int c = count(s.begin(), s.end(), 'R');
	solve(a, b, c);

	if (vis[1][0][0])
		cout << "B";
	if (vis[0][1][0])
		cout << "G";
	if (vis[0][0][1])
		cout << "R";
}