#include <bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Why_Are_You_So_Orz();

signed main(){
#ifndef ONLINE_JUDGE
	FAST_IO("input.inp", "output.out");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("mike4235orz.inp", "mike4235orz.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++)
		Why_Are_You_So_Orz();
#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 505;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;
char s[N][N];

bool check(int x, int y) {
	int ok = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (s[nx][ny] == '.') ok ^= 1;
	}
	return ok;
}

int res[N][N];

void Why_Are_You_So_Orz() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> (s[i] + 1);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'X' && !check(i, j))
				return cout << "NO", (void) 0;


	for (int i = 1; i <= n; i++)
		for (int j = 1, k = 0; j <= m; j++)
			if (s[i][j] == '.')
				res[i][j] = i + k & 1 ? 1 : 4;
			else if (s[i - 1][j] == 'X')
				k ^= 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'X')
				for (int d = 0; d < 4; d++) {
					int x = i + dx[d], y = j + dy[d];
					if (s[x][y] == '.')
						res[i][j] += res[x][y];
				}
	
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cout << res[i][j] << " \n"[j == m];
}