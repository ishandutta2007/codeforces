#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
typedef long long lint;
typedef pair<int, int> pi;

struct state{
	int odd, even;
	int oddf, evenf;
};

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
	state min(state l, state r){
		state x;
		if(l.odd <= r.odd) x.odd = l.odd, x.oddf = l.oddf;
		else x.odd = r.odd, x.oddf = r.oddf;
		if(l.even <= r.even) x.even = l.even, x.evenf = l.evenf;
		else x.even = r.even, x.evenf = r.evenf;
		return x;
	}
	vector<state> minimum_partition(int n, char *str){ // (odd min, even min)
		vector<state> dp(n + 1);
		vector<state> series_ans(n + 10);
		dp[0] = {(int)1e9 + 1, 0, 0, 0};
		for(int i=1; i<=n; i++){
			dp[i] = {(int)1e9 + 1, (int)1e9, i, i};
			if(i % 2 == 0 && str[i-1] == str[i]){
				auto v = dp[i-2];
				v.oddf = v.evenf = i-2;
				dp[i] = min(dp[i], v);
			}
			for(int j=ptr[i]; len[j] > 0;){
				int slv = slink[series[j]];
				auto x = dp[i - len[slv] - diff[j]];
				x.oddf = x.evenf = i - len[slv] - diff[j];
				series_ans[j] = x;
				if(diff[j] == diff[slink[j]]){
					series_ans[j] = min(series_ans[j], series_ans[slink[j]]);
				}
				auto val = series_ans[j];
				tie(val.odd, val.even) = pi(val.even + 1, val.odd + 1);
				swap(val.oddf, val.evenf);
				dp[i] = min(dp[i], val);
				j = slv;
			}
			if(i & 1){
				dp[i].odd = 1e9 + 1;
				dp[i].even = 1e9;
			}
		}
		return dp;
	}
};

int n;
char buf1[MAXN], buf2[MAXN];
char str[MAXN];

int main(){
	scanf("%s %s", buf1, buf2);
	n = strlen(buf1) * 2;
	for(int i=0; i<n/2; i++){
		str[2 * i + 1] = buf1[i] - 'a';
		str[2 * i + 2] = buf2[i] - 'a';
	}
	eertree::init(n, str);
	auto x = eertree::minimum_partition(n, str);
	if(min(x[n].odd, x[n].even) > 1e7){
		puts("-1");
		return 0;
	}
	cout << min(x[n].odd, x[n].even) << endl;
	vector<pi> trk;
	int pos = n;
	while(pos){
		if(x[pos].odd <= x[pos].even){
			if(x[pos].oddf < pos - 2){
				trk.push_back(pi(x[pos].oddf / 2 + 1, pos / 2));
				pos = x[pos].oddf;
			}
			else pos -= 2;
		}
		else{
			if(x[pos].evenf < pos - 2){
				trk.push_back(pi(x[pos].evenf / 2 + 1, pos / 2));
				pos = x[pos].evenf;
			}
			else pos -= 2;
		}
	}
	for(auto &i : trk) printf("%d %d\n", i.first, i.second);
}