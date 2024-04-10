#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

string grid[100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		ll R, C;
		cin >> R >> C;
		for(ll i = 0; i < R; i++) cin >> grid[i];
		bool p = false, corn = false, side = false, edge = false, row = false, inter = false;
		corn = grid[0][0] == 'A' || grid[R - 1][0] == 'A' || grid[0][C - 1] == 'A' || grid[R - 1][C - 1] == 'A';
		for(ll i = 0; i < R; i++)
			for(ll j = 0; j < C; j++)
				if(grid[i][j] == 'A') {
					if(i == 0 || i == R - 1 || j == 0 || j == C - 1) edge = true;
					else inter = true;
				} else p = true;
		for(ll c = 0; c < C; c++) {
			bool temp = true;
			for(ll r = 0; r < R; r++) if(grid[r][c] == 'P') temp = false;
			if(temp) {
				if(c == 0 || c == C - 1) side = true;
				row = true;
			}
		}
		for(ll r = 0; r < R; r++) {
			bool temp = true;
			for(ll c = 0; c < C; c++) if(grid[r][c] == 'P') temp = false;
			if(temp) {
				if(r == 0  || r == R - 1) side = true;
				row = true;
			}
		}
		if(!p) cout << 0 << endl;
		else if(side) cout << 1 << endl;
		else if(corn || row) cout << 2 << endl;
		else if(edge) cout << 3 << endl;
		else if(inter) cout << 4 << endl;
		else cout << "MORTAL" << endl;
	}
	return 0;
}