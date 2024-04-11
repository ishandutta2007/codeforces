#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e2 + 5, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char mat[60][60];
int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!mat[i][j]) continue;
			for(int x = 1; x <= n; x++) {
				for(int y = 1; y <= m; y++) {
					if(mat[i][j]=='#'&&mat[x][j]=='#'&&mat[i][y]=='#') {
						if(mat[x][y]!='#') return cout << "No", 0;
					}
				}
			}
		}
	}
	cout << "Yes";
	return 0;
}