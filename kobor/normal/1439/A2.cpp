#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

bool mk[110][110];
vector<vector<ii>> out;
int n, m;

void klik(int i1, int j1, int i2, int j2, int i3, int j3){
	mk[i1][j1] ^= 1;
	mk[i2][j2] ^= 1;
	mk[i3][j3] ^= 1;
	out.PB({{i1, j1}, {i2, j2}, {i3, j3}});
}

void napraw(){
	int sum = 0;
	FOR(i, n-2, n) FOR(j, m-2, m) sum += mk[i][j];
	vector<ii> xd[2];
	FOR(i, n-2, n) FOR(j, m-2, m) xd[mk[i][j]].PB({i, j});
	if(sum == 0) return;
	if(sum == 1 || sum == 2){
		klik(xd[1][0].X, xd[1][0].Y, xd[0][0].X, xd[0][0].Y, xd[0][1].X, xd[0][1].Y);
	}
	if(sum == 3 || sum == 4){
		klik(xd[1][0].X, xd[1][0].Y, xd[1][1].X, xd[1][1].Y, xd[1][2].X, xd[1][2].Y);
	}
	napraw();
}

void solve(){
	cin >> n >> m;
	FOR(i, 0, n){
		string s;
		cin >> s;
		FOR(j, 0, m) mk[i][j] = s[j] == '1';
	}
	FOR(i, 0, n-2){
		FOR(j, 0, m){
			if(mk[i][j]){
				if(j == m-1) klik(i, j, i+1, j-1, i+1, j);
				else klik(i, j, i, j+1, i+1, j);
			}
		}
	}
	FOR(j, 0, m-2){
		int i = n-2;
		if(mk[i][j]) klik(i, j, i, j+1, i+1, j);
		if(mk[i+1][j]) klik(i+1, j, i+1, j+1, i, j+1);
	}
	napraw();
	cout << SZ(out) << '\n';
	TRAV(x, out){
		TRAV(y, x) cout << y.X+1 << ' ' << y.Y+1 << ' ';
		cout << '\n';
	}
	out.clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}