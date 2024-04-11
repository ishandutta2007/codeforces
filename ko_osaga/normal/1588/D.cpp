#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1600;

int nxt[11][111][52];
vector<int> occur[11][52];

int dp[105][512];
pi trk[105][512];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		memset(nxt, 0, sizeof(nxt));
		for(int i = 0; i < 11; i++){
			for(int j = 0; j < 52; j++){
				occur[i][j].clear();
			}
		}
		int n; cin >> n;
		vector<string> s(n);
		lint prominent = (1ll << 52) - 1;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			lint msk = 0;
			for(auto &j : s[i]){
				if(isupper(j)) j -= 'A';
				else j -= 'a' - 26;
				msk |= (1ll << j);
			}
			prominent &= msk;
		}
		for(int i = 0; i < n; i++){
			string t;
			for(auto &j : s[i]){
				if((prominent >> j) & 1) t.push_back(j);
			}
			s[i] = t;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < sz(s[i]); j++){
				for(int k = 0; k < 52; k++){
					if(s[i][j] == k) nxt[i][j][k] = j;
					else nxt[i][j][k] = (j == 0 ? -1 : nxt[i][j - 1][k]);
				}
			}
			for(int j = 0; j < sz(s[i]); j++){
				occur[i][s[i][j]].push_back(j);
			}
		}
		memset(dp, 0, sizeof(dp));
		int tot = 0;
		pi stpos(-1, -1);
		for(int i = 0; i < sz(s[n - 1]); i++){
			char c = s[n - 1][i];
			for(int j = 0; j < (1<<(n - 1)); j++){
				bool ok = 1;
				vector<int> pos(n); pos[n - 1] = i;
				for(int k = 0; k < n-1; k++){
					if((j >> k) & 1){
						if(sz(occur[k][c]) == 1){
							ok = 0;
							break;
						}
					}
					pos[k] = occur[k][c][(j >> k) & 1];
				}
				if(ok == 0) continue;
				for(int k = 0; k < 52; k++){
					vector<int> nxtpos(n);
					for(int x = 0; x < n; x++){
						if(pos[x] == 0) nxtpos[x] = -1;
						else{
							nxtpos[x] = nxt[x][pos[x] - 1][k];
						}
					}
					if(count(all(nxtpos), -1)) continue;
					int msk = 0;
					for(int x = 0; x < n - 1; x++){
						if(occur[x][k][0] != nxtpos[x]) msk |= (1<<x);
					}
					if(dp[i][j] < dp[nxtpos[n - 1]][msk]){
						dp[i][j] = dp[nxtpos[n - 1]][msk];
						trk[i][j] = pi(nxtpos[n - 1], msk);
					}
				}
				dp[i][j]++;
				if(dp[i][j] > tot){
					tot = dp[i][j];
					stpos = pi(i, j);
				}
			}
		}
		if(tot == 0) cout << "0\n\n";
		else{
			cout << tot << "\n";
			vector<int> v;
			for(int i = 0; i < tot; i++){
				v.push_back(s[n - 1][stpos.first]);
				stpos = trk[stpos.first][stpos.second];
			}
			reverse(all(v));
			for(auto &i : v){
				if(i < 26) cout << (char)(i + 'A');
				else cout << (char)(i - 26 + 'a');
			}
			cout << "\n";
		}
	}
}