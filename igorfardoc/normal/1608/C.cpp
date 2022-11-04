#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi gr;

bool cmp(const array<int, 3>& a, const array<int, 3>& b) {
	return a[1] < b[1];
}
vi ans;
vector<bool> used;

void dfs(int v) {
	used[v] = true;
	ans[v] = 1;
	for(int u : gr[v]) {
		if(used[u]) continue;
		dfs(u);
	}
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
    	int n;
    	cin >> n;
    	gr.assign(n, vi(0));
    	vector<array<int, 3>> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i][0];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> a[i][1];
    		a[i][2] = i;
    	}
    	sort(a.begin(), a.end());
    	for(int i = 0; i < n - 1; i++) {
    		gr[a[i][2]].push_back(a[i + 1][2]);
    	}
    	sort(a.begin(), a.end(), cmp);
    	for(int i = 0; i < n - 1; i++) {
    		gr[a[i][2]].push_back(a[i + 1][2]);
    	}
    	ans.assign(n, 0);
    	used.assign(n, false);
    	dfs(a[n - 1][2]);
    	for(const auto& el : ans) {
    		cout << el;
    	}
    	cout << '\n';
    }

}