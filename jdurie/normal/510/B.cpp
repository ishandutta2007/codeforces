#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

char grid[100][100];
bool used[100][100];
ll n, m;
ll dx[] = {1, 0, 0, -1};
ll dy[] = {0, 1, -1, 0};

void loop(int i, int j, int tI, int tJ, int dir) {
	if(used[i][j]) {
		cout << "Yes" << endl;
		exit(0);
	}
	used[i][j] = true;
	for(int k = 0; k < 4; k++)
		if(k != dir && grid[i + dx[k]][j + dy[k]] == grid[i][j])
			loop(i + dx[k], j + dy[k], tI, tJ, 3 - k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	memset(grid, '$', sizeof(grid));
	for(ll i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for(ll j = 1; j <= m; j++) grid[i][j] = s[j - 1];
	}
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= m; j++)
			if(!used[i][j])
				loop(i, j, i, j, -1);
	cout << "No" << endl;
}