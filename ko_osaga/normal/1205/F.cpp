#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
const int MAXN = 105;
using lint = long long;

vector<int> gph[MAXN*2];
int typ[MAXN*2];
void apply_simple(vector<int> &v){
	reverse(all(v));
	int n = sz(v);
	if(n & 1) n--;
	int x = 0, y = n / 2;
	vector<int> ret;
	while(x < n / 2 || y < n){
		if(y < n) ret.push_back(v[y++]);
		if(x < n / 2) ret.push_back(v[x++]);
	}
	if(sz(v) != n){
		ret.insert(ret.begin() + n/2-1, v[n]);
	}
	v = ret;
}

void dfs(int x, int thr, vector<int> &v, int rev){
	if(x <= thr) v.push_back(x);
	else if(typ[x]) apply_simple(gph[x]);
	else{
		if(rev) reverse(all(gph[x]));
	}
	for(auto &i : gph[x]) dfs(i, thr, v, rev ^ 1);
}

vector<vector<int>> v;
vector<int> ans[MAXN][5111];
int dp[MAXN][5111];
int trk[MAXN][5111];
void solve(){
	for(int i=1; i<=100; i++){
		memset(dp, 0, sizeof(dp));
		dp[i][i] = 1;
		for(int j=i; j>=1; j--){
			for(int k=0; k<=i*(i+1)/2; k++){
				if(!dp[j][k]) continue;
				for(int l=2; l<=j; l++){
					if(!dp[j - l + 1][k + l * (l - 1) / 2]){
						dp[j - l + 1][k + l * (l - 1) / 2] = 1;
						trk[j - l + 1][k + l * (l - 1) / 2] = 2 * l;
					}
					if(l >= 4 && !dp[j - l + 1][k + 1]){
						dp[j - l + 1][k + 1] = 1;
						trk[j - l + 1][k + 1] = 2 * l + 1;
					}
				}
			}
		}
		for(int j=0; j<=5050; j++){
			if(sz(ans[i][j]) && dp[1][j]){
				vector<int> seq;
				int x = 1, y = j;
				while(x < i){
					int ans = trk[x][y];
					seq.push_back(ans);
					if(ans & 1){
						ans >>= 1;
						x += ans - 1;
						y -= 1;
					}
					else{
						ans >>= 1;
						x += ans - 1;
						y -= ans * (ans - 1) / 2;
					}
				}
				for(int i=0; i<2*MAXN; i++) gph[i].clear();
				reverse(all(seq));
				vector<int> tans(i);
				iota(all(tans), 1);
				int cnt = i;
				for(auto &i : seq){
					cnt++;
					for(int j=0; j<i/2; j++){
						gph[cnt].push_back(tans.back());
						tans.pop_back();							
					}
					typ[cnt] = i & 1;
					tans.push_back(cnt);
				}
				vector<int> rans;
				dfs(cnt, i, rans, 0);
				for(auto &k : ans[i][j]) v[k] = rans;
			}
		}
	}
}


int main(){
	int cnt = 0;
	for(int i=1; i<=1; i++){
		int qr; scanf("%d",&qr);
		for(int j=0; j<qr; j++){
			int n, k;
			scanf("%d %d",&n,&k);
			ans[n][k].push_back(cnt++);
		}
	}
	v.resize(cnt);
	solve();
	for(int i=0; i<cnt; i++){
		if(sz(v[i])){
			puts("YES");
			for(auto &j : v[i]) printf("%d ", j);
			puts("");
		}
		else puts("NO");
	}
}