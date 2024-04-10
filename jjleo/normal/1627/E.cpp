#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, m, k;
int x[maxn], h[maxn];
vector<pair<int, int> > v[maxn], w[maxn];
ll val[maxn];


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &x[i]), v[i].clear(), w[i].clear();
		for(int i = 1;i <= k;i++){
			int a, b, c, d;
			scanf("%d%d%d%d%d", &a, &b, &c, &d, &h[i]);
			v[a].push_back({b, i}), w[c].push_back({d, i});
			val[i] = 1e18;
		}
		v[n].push_back({m, k + 1}), val[k + 1] = 1e18;
		for(int i = 1;i <= n;i++) sort(v[i].begin(), v[i].end()), sort(w[i].begin(), w[i].end());
		for(int i = 1;i <= n;i++){
			int pos = -1;
			ll sum = 1e18;
			if(i == 1) sum = -x[i];
			for(int j = 0;j < v[i].size();j++){
				while(pos + 1 < w[i].size() && w[i][pos + 1].first <= v[i][j].first){
					pos++, sum = min(sum, val[w[i][pos].second] - 1ll * w[i][pos].first * x[i] - h[w[i][pos].second]);
				}
				val[v[i][j].second] = min(val[v[i][j].second], sum + 1ll * v[i][j].first * x[i]);
			}
			pos = w[i].size();
			sum = 1e18;
			for(int j = (int)v[i].size() - 1;~j;j--){
				while(pos && w[i][pos - 1].first >= v[i][j].first){
					pos--, sum = min(sum, val[w[i][pos].second] + 1ll * w[i][pos].first * x[i] - h[w[i][pos].second]);
				}
				val[v[i][j].second] = min(val[v[i][j].second], sum - 1ll * v[i][j].first * x[i]);
			}
		}
		if(val[k + 1] >= 1e17) puts("NO ESCAPE");
		else printf("%lld\n", val[k + 1]);
	}
}
/*
1
5 5 1
0 0 0 0 0
1 1 5 5 1
*/