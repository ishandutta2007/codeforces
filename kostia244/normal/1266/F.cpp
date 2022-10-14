#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<19;
int n, answer[maxn];
vector<int> g[maxn];
array<int, 2> furthest(int v, int p) {
	array<int, 2> ans = {0, v};
	for(auto &i : g[v]) if(i != p) {
		auto t = furthest(i, v);
		t[0]++;
		ans = max(ans, t);
	}
	return ans;
}

int p[maxn], h[maxn], h2[maxn], th[maxn];
vector<int> ch[maxn];
void dfs(int v) {
	for(auto &i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		p[i] = v;
		dfs(i);
		h[v] = max(h[v], h[i] + 1);
		ch[v].push_back(h[i]+1);
	}
	sort(all(ch[v]));
	h2[v] = ch[v].size()>1?ch[v][ch[v].size()-2]:0;
}

void top(int v) {
	for(auto &i : g[v]) {
		th[i] = max(th[v] + 1, (h[i]+1==h[v]?h2[v]:h[v])+1);
		top(i);
	}
}

int count(int v, int block, int d, int extra) {
	int c = ch[v].end() - lower_bound(all(ch[v]), d);
	if(block != -1) c += (th[v])>=d;
	if(block >= 0) c -= h[block] >= d;
	if(extra) c += !!binary_search(all(ch[v]), d-1) || (d-1 == 0) || th[v] == d-1;
	//cout << v << " " << block << " " << d << " " << extra << endl;
	return c;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	int diameter = 0;
	{
		int v1 = furthest(1, 0)[1];
		diameter = furthest(v1, 0)[0];
	}
	dfs(1);
	top(1);
	
	for(int v = 1; v <= n;v++) {
		for(int d = 1; d <= min(2*h2[v] + 2, n); d++) {
			int l = d/2, r = l+1;
			answer[d] = max(answer[d], count(v, -2, (d&1) + l, d&1));
			if((d&1) || v==1) continue;
			answer[d] = max(answer[d], count(v, -1, l, 0) + count(p[v], v, l, 0));
		}
	}
	for(int i = 1; i <= n; i++) {
		answer[i] = max(answer[i], 1 + (i <= diameter));
		cout << answer[i] << " ";
	}
	cout << '\n';
}