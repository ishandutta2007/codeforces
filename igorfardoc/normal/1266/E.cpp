#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi a, am;
int n;
ll ans;
map<pair<int, int>, int> d;

void delete1(int s, int t) {
	auto it = d.find({s, t});
	if(it == d.end()) {
		return;
	}
	int u = (*it).second;
	ans += min(a[u], am[u]);
	--am[u];
	ans -= min(a[u], am[u]);
	d.erase(it);
}

void add(int s, int t, int u) {
	ans += min(a[u], am[u]);
	d[{s, t}] = u;
	++am[u];
	ans -= min(a[u], am[u]);
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
    int n;
    cin >> n;
    a.resize(n);
    ans = 0;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	ans += a[i];
    }
    am.assign(n, 0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
    	int s, t, u;
    	cin >> s >> t >> u;
    	--s;
    	--u;
    	delete1(s, t);
    	if(u != -1) {
    		add(s, t, u);
    	}
    	cout << ans << '\n';
    }
}