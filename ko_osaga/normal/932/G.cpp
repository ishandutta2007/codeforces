#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
typedef long long lint;
typedef pair<int, int> pi;

namespace eertree{
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
	int query(int s, int e){
		int pos = ptr[e];
		while(len[pos] >= e - s + 1){
            if(len[pos] % diff[pos] == (e - s + 1) % diff[pos] &&
               len[series[pos]] <= e - s + 1) return true;
            pos = series[pos];
            pos = slink[pos];
		}
		return false;
	}
	int add(int x, int y){ return (x + y) % 1000000007; }
	vector<pi> minimum_partition(int n){ // (odd sum0, even sum);
		vector<pi> dp(n + 1);
		vector<pi> series_ans(n + 10);
		dp[0] = pi(0, 1);
		for(int i=1; i<=n; i++){
			dp[i] = pi(0, 0);
			for(int j=ptr[i]; len[j] > 0;){
				int slv = slink[series[j]];
				series_ans[j] = dp[i - (len[slv] + diff[j])];
				assert(len[slv] + diff[j] != 0);
				if(diff[j] == diff[slink[j]]){
					series_ans[j].first = add(series_ans[j].first, series_ans[slink[j]].first);
					series_ans[j].second = add(series_ans[j].second, series_ans[slink[j]].second);
				}
				auto val = series_ans[j];
				dp[i].first = add(dp[i].first, val.second);
				dp[i].second = add(dp[i].second, val.first);
				j = slv;
			}
			if(i & 1) dp[i] = pi(0, 0);
		}
		return dp;
	}
}

int n;
char str[MAXN];

int main(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	if(n & 1){
		puts("0");
		return 0;
	}
	string c;
	for(int i=1; i<=n/2; i++) c.push_back(str[i]), c.push_back(str[n+1-i]);
	for(int i=1; i<=n; i++) str[i] = c[i-1] - 'a';
	eertree::init(n, str);
	auto x = eertree::minimum_partition(n)[n];
	cout << (x.first + x.second) % 1000000007 << endl;
}