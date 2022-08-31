#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAXN = 1005;


int n;
bool chk[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++) chk[0][i] = 0, chk[1][i] = 1;
		for(int i = 2; i < n; i++) for(int j = 0; j < n; j++) chk[i][j] = 0;
		for(int i = 2; i < n; i++){
			for(int j = 0; j < n; j++){
				int x = i - 1, y = j;
				bool ans = 0;
				for(int k = 0; k < 4; k++){
					if(x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < n) ans ^= chk[x + dx[k]][y + dy[k]];
				}
				chk[i][j] = (ans ^ 1);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int x = i, y = j;
				bool ans = 0;
				for(int k = 0; k < 4; k++){
					if(x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < n) ans ^= chk[x + dx[k]][y + dy[k]];
				}
			//	if(ans != 1) cout << i << " " << j << endl;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int x; cin >> x;
				if(chk[i][j]) ans ^= x;
			}
		}
		cout << ans << "\n";
	}
}