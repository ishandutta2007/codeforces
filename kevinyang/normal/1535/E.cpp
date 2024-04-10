#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp(300005,vector<int>(20));
vector<int>val(300005);
vector<int>wt(300005);

int ln = 20;

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q,a0,c0;
	cin >> q >> a0 >> c0;
	val[0] = a0;
	wt[0] = c0;
	for(int u = 1; u<=q; u++){
		int cm;
		cin >> cm;
		if(cm==1){
			int p,a,c;
			cin >> p >> a >> c;
			dp[u][0] = p;
			for(int i = 1; i<ln; i++){
				dp[u][i] = dp[dp[u][i-1]][i-1];
			}
			val[u] = a;
			wt[u] = c;
		}
		else{
			int v,w;
			cin >> v >> w;
			int oldw = w;
			int old = v;
			int ans = 0;
			while(w){
				v = old;
				if(val[v]==0)break;
				for(int i = ln-1; i>=0; i--){
					if(val[dp[v][i]]){
						v = dp[v][i];
					}
				}
				if(val[v]<=w){
					ans+=val[v]*wt[v];
					w-=val[v];
					val[v] = 0;
				}
				else{
					ans+=w*wt[v];
					val[v]-=w;
					w = 0;
				}
			}
			cout << oldw-w << " " << ans << endl;
		}
	}
	return 0;
}