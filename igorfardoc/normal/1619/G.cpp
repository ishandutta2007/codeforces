#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vector<bool> used;
vi x, y, timer;

int dfs(int v) {
	used[v] = true;
	int res = timer[v];
	for(int u : g[v]) {
		if(used[u]) continue;
		res = min(res, dfs(u));
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	g.assign(n, vi(0));
    	x.resize(n);
    	y.resize(n);
    	timer.resize(n);

    	for(int i = 0; i < n; i++) {
    		cin >> x[i] >> y[i] >> timer[i];
    	}
    	map<int, set<pair<int, int>>> dx, dy;
    	for(int i = 0; i < n; i++) {
    		dx[x[i]].insert({y[i], i});
    		dy[y[i]].insert({x[i], i});
    	}
    	for(const auto& el : dx) {
    		vi here;
    		for(const auto& el1 : el.second) {
    			here.push_back(el1.second);
    		}
    		for(int i = 0; i < (int)here.size() - 1; i++) {
    			if(y[here[i]] + k >= y[here[i + 1]]) {
    				g[here[i]].push_back(here[i + 1]);
    				g[here[i + 1]].push_back(here[i]);
    			}
    		}
    	}
    	for(const auto& el : dy) {
    		vi here;
    		for(const auto& el1 : el.second) {
    			here.push_back(el1.second);
    		}
    		for(int i = 0; i < (int)here.size() - 1; i++) {
    			if(x[here[i]] + k >= x[here[i + 1]]) {
    				g[here[i]].push_back(here[i + 1]);
    				g[here[i + 1]].push_back(here[i]);
    			}
    		}
    	}
    	used.assign(n, false);
    	vi min1;
    	for(int i = 0; i < n; i++) {
    		if(used[i]) continue;
    		min1.push_back(dfs(i));
    	}
    	sort(min1.begin(), min1.end());
    	int l = -1;
    	int r = (int)min1.size() - 1;
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		if(min1[min1.size() - mid - 2] <= mid) {
    			r = mid;
    		} else {
    			l = mid;
    		}
    	}
    	cout << r << '\n';
    }
}