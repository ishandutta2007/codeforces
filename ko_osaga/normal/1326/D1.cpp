#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;

struct eertree{
	int nxt[MAXN][26];
	int par[MAXN], len[MAXN], slink[MAXN], ptr[MAXN], diff[MAXN], series[MAXN], piv;
	void clear(int n = MAXN){
		memset(par, 0, sizeof(int) * n);
		memset(len, 0, sizeof(int) * n);
		memset(slink, 0, sizeof(int) * n);
		memset(nxt, 0, sizeof(int) * 26 * n);
		piv = 0;
	}
	void init(int n, char *a){
		par[0] = 0;
		par[1] = 1;
		a[0] = -1;
		len[0] = -1;
		piv = 1;
		int cur = 1;
		for(int i=1; i<=n; i++){
			while(a[i] != a[i - len[cur] - 1]) cur = slink[cur];
			if(!nxt[cur][a[i]]){
				nxt[cur][a[i]] = ++piv;
				par[piv] = cur;
				len[piv] = len[cur] + 2;
				int lnk = slink[cur];
				while(a[i] != a[i - len[lnk] - 1]){
					lnk = slink[lnk];
				}
				if(nxt[lnk][a[i]]) lnk = nxt[lnk][a[i]];
				if(len[piv] == 1 || lnk == 0) lnk = 1;
				slink[piv] = lnk;
				diff[piv] = len[piv] - len[lnk];
				if(diff[piv] == diff[lnk]) series[piv] = series[lnk];
				else series[piv] = piv;
			}
			cur = nxt[cur][a[i]];
			ptr[i] = cur;
		}
	}
	int query(int l, int p){
		int pos = ptr[p];
		while(len[pos] > l) pos = slink[pos];
		return len[pos];
	}
	vector<pi> minimum_partition(int n){ // (odd min, even min)
		vector<pi> dp(n + 1);
		vector<pi> series_ans(n + 10);
		dp[0] = pi(1e9 + 1, 0);
		for(int i=1; i<=n; i++){
			dp[i] = pi(1e9 + 1, 1e9);
			for(int j=ptr[i]; len[j] > 0;){
				int slv = slink[series[j]];
				series_ans[j] = dp[i - (len[slv] + diff[j])];
				if(diff[j] == diff[slink[j]]){
					series_ans[j].first = min(series_ans[j].first, series_ans[slink[j]].first);
					series_ans[j].second = min(series_ans[j].second, series_ans[slink[j]].second);
				}
				auto val = series_ans[j];
				dp[i].first = min(dp[i].first, val.second + 1);
				dp[i].second = min(dp[i].second, val.first + 1);
				j = slv;
			}
		}
		return dp;
	}
}waterloo;

int n;
char str[MAXN];

string Sex(){
	waterloo.clear(n + 2);
	waterloo.init(n, str);
	int m = 0;
	while((m+1)*2 <= n && str[m+1] == str[n-m]) m++;
	pi ret(-1, 0);
	for(int i=0; i<=m; i++){
		ret = max(ret, pi(waterloo.query(n - 2 * i, n - i) + 2 * i, i));
	}
	int s = ret.second;
	int e = n - ret.first + ret.second;
	string tmp;
	for(int i=0; i<s; i++) tmp.push_back(str[i + 1] + 'a');
	for(int i=e; i<n; i++) tmp.push_back(str[i + 1] + 'a');
	return tmp;
}

int main(){
	int t; scanf("%d",&t);
	for(int i=0; i<t; i++){
		scanf("%s", str + 1);
		n = strlen(str + 1);
		for(int i=1; i<=n; i++) str[i] -= 'a';
		auto l = Sex();
		reverse(str + 1, str + n + 1);
		auto r = Sex();
		if(sz(l) > sz(r)) swap(l, r);
		puts(r.c_str());
	}
}