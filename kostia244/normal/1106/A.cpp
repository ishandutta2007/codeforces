#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
inline void getv(vector<T>& v) {
	for (auto& i : v)
		cin >> i;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, c = 0;
	cin >> n;
	vector<vector<char>> mat(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && i < (n - 1) && j > 0 && j < (n - 1)
					&& mat[i][j] == 'X') {
				c +=
						(mat[i + 1][j + 1] == 'X' && mat[i + 1][j - 1] == 'X'
								&& mat[i - 1][j + 1] == 'X'
								&& mat[i - 1][j - 1] == 'X');
			}
		}
	}

	cout << c;

}