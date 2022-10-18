#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < e; i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int N = 1010;

int pref[N][N];

int sum(int x2, int y2, int x1, int y1){
	return pref[x1+1][y1+1]-pref[x2][y1+1]-pref[x1+1][y2]+pref[x2][y2];
}

void solve(){
	int n, m;
	cin >> n >> m;
	vi row(n), col(m);
	FOR(i, 0, n){
		FOR(j, 0, m){
			char c;
			cin >> c;
			if(c == '*') pref[i+1][j+1] = 1;
		}
	}
	FOR(i, 0, n){
		FOR(j, 0, m){
			pref[i+1][j+1] += pref[i+1][j]+pref[i][j+1]-pref[i][j];
		}
	}
	FOR(i, 0, n){
		FOR(j, 0, m){
			if(sum(i, 0, i, m-1) + sum(0, j, n-1, j) - sum(i, j, i, j) == sum(0, 0, n-1, m-1)){
				cout << "YES\n";
				cout << i+1 << ' ' << j+1 << '\n';
				return;
			}
		}
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}