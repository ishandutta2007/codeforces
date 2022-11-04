#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> good;
    set<pair<int, int>> bad;
    map<pair<int, int>, char> g;
    for(int i = 0; i < m; i++) {
    	char c;
    	cin >> c;
    	if(c == '?') {
    		int k;
    		cin >> k;
    		if((k % 2 == 0 && !good.empty()) || (k % 2 == 1 && !bad.empty())) {
    			cout << "YES\n";
    		} else {
    			cout << "NO\n";
    		}
    	} else if(c == '+') {
    		int v, u;
    		char c;
    		cin >> v >> u >> c;
    		--v;
    		--u;
    		g[{v, u}] = c;
    		auto it = g.find({u, v});
    		if(it != g.end()) {
    			bad.insert({min(v, u), max(v, u)});
    			if(c == it->second) {
    				good.insert({min(v, u), max(v, u)});
    			}
    		}
    	} else {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g.erase(g.find({v, u}));
    		auto it = bad.find({min(v, u), max(v, u)});
    		if(it != bad.end()) {
    			bad.erase(it);
    		}
    		it = good.find({min(v, u), max(v, u)});
    		if(it != good.end()) {
    			good.erase(it);
    		}
    	}
    }
}