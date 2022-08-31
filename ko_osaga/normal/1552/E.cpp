#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int a[22];

int main(){
		int n, k;
		cin >> n >> k;
		vector<int> a(n*k);
		vector<int> vis(n + 1);
		vector<vector<int>> stk(n + 1);
		vector<pi> ans(n + 1);
		for(auto &i : a) cin >> i;
		int cnt = 0;
		int T = (n + k - 2) / (k - 1);
		for(int i = 0; i < sz(a); i++){
			if(vis[a[i]]) continue;
			stk[a[i]].push_back(i+1);
			if(sz(stk[a[i]]) == 2){
				ans[a[i]] = pi(stk[a[i]][0], stk[a[i]][1]);
				vis[a[i]] = 1;
				cnt++;
				if(cnt == T){
					for(int j = 0; j <= n; j++) stk[j].clear();
					cnt = 0;
				}
			}
		}
		for(int i = 1; i <= n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
}