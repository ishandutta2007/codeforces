#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 200005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<lint, lint>;

int n, m, a[2001][13];
int prv[1 << 12], nxt[1 << 12], dp[1 << 12];

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&m,&n);
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				scanf("%d",&a[j][i]);
			}
		}
		vector<pi> v;
		for(int i=0; i<n; i++){
			int mx = *max_element(a[i], a[i] + m);
			v.emplace_back(mx, i);
		}
		sort(v.rbegin(), v.rend());
		set<int> mark;
		for(int i=0; i<min(n, m); i++) mark.insert(v[i].second);
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<n; i++){
			if(mark.find(i) == mark.end()) continue;
			memcpy(prv, dp, sizeof(prv));
			memset(dp, 0, sizeof(dp));
			for(int j=0; j<m; j++){
				rotate(a[i], a[i] + 1, a[i] + m);
				memcpy(nxt, prv, sizeof(nxt));
				for(int k=1; k<(1<<m); k++){
					for(int l=0; l<m; l++){
						if((k >> l) & 1) nxt[k] = max(nxt[k], nxt[k ^ (1<<l)] + a[i][l]);
					}
				}
				for(int k=0; k<(1<<m); k++) dp[k] = max(dp[k], nxt[k]);
			}
		}
		cout << dp[(1 << m) - 1] << endl;
	}
}