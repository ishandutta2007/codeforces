#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 110005;
const int mod = 1e9 + 7;

vector<int> gph[MAXN];
vector<int> seq[MAXN];
int T[MAXN], n, m, q, idx[MAXN];
lint ans[MAXN], dx[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		int x; scanf("%d",&x);
		seq[x].push_back(i);
		idx[i] = x;
	}
	for(int i=1; i<=n; i++) seq[i].push_back(q+1);
	for(int i=1; i<=n; i++){
		if(sz(seq[i]) > 100){
			memset(T, 0, sizeof(T));
			int up = 0, dn = 0;
			for(auto &j : gph[i]){
				if(j > i) T[j] = j, up++;
				else T[j] = j, dn++;
			}
			T[i] = i;
			ans[0] += 1ll * up * dn;
			for(int j=1; j<=q; j++){
				if(i == idx[j]){
					dn += up; up = 0;
				}
				else if(T[idx[j]]){
					if(T[idx[j]] < T[i]){
						dn--;
						up++;
					}
				}
				if(T[idx[j]]){
					T[idx[j]] = j + n;
				}
				ans[j] += 1ll * up * dn;
			}
		}
		else{
			vector<pi> diff;
			int dnC = 0;
			for(auto &j : gph[i]){
				int curWinning = (j < i);
				if(curWinning) diff.emplace_back(0, 1);
				if(curWinning && seq[j][0] < seq[i][0]){
					diff.emplace_back(seq[j][0], -1);
					curWinning = 0;
				}
				for(int k=0; k<sz(seq[i])-1; k++){
					int curStart = seq[i][k];
					int curEnd = seq[i][k+1];
					auto bs = upper_bound(seq[j].begin(), seq[j].end(), curStart);
					if(bs != seq[j].end() && *bs < curEnd){
						if(!curWinning) diff.emplace_back(curStart, 1);
						diff.emplace_back(*bs, -1);
						curWinning = 0;
					}
					else{
						if(!curWinning){
							diff.emplace_back(curStart, 1);
						}
						curWinning = 1;
					}
				}
			}
			int tot = sz(gph[i]);
			diff.emplace_back(0, 0);
			sort(diff.begin(), diff.end());
			diff.emplace_back(q + 100, 0);
			dnC = 0;
			for(int i=0; i<sz(diff)-1; i++){
				dnC += diff[i].second;

				dx[diff[i].first] += 1ll * dnC * (tot - dnC);
				dx[diff[i+1].first] -= 1ll * dnC * (tot - dnC);
			}
		}
	}
	for(int i=1; i<=q; i++) dx[i] += dx[i-1];
	for(int i=0; i<=q; i++) printf("%lld\n", dx[i] + ans[i]);
}