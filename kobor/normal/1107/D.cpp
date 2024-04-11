#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

int n;
bool t[5205][5205];

void solve(){
	cin >> n;
	FOR(i, 0, n){
		string s;
		cin >> s;
		FOR(j, 0, n/4){
			if(s[j] <= '9') s[j] -= '0';
			else s[j] -= 'A' - 10;
			FOR(k, 0, 4) t[i][j*4+k] = (s[j]>>(3-k)) & 1;
		}
	}
	for(int r = n; r >= 1; r--){
		if(n % r) continue;
		bool ok = 1;
		for(int i = 0; i < n; i += r){
			for(int j = 0; j < n; j += r){
				FOR(i2, i, i+r){
					FOR(j2, j, j+r){
						ok &= t[i][j] == t[i2][j2];
					}
				}
			}
		}
		if(ok){
			cout << r << '\n';
			break;
		}
	}
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