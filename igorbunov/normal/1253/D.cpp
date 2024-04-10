#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

vector<int> g[300000];

vector<bool> used(300000);

void dfs(int v, int &min1, int &max1) {
	used[v] = true;
	min1 = min(min1, v);
	max1 = max(max1, v);

	for (auto u: g[v]) {
		if (!used[u]) {
			dfs(u, min1, max1);
		}
	}
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    vector<pair<int, int>> comp;
    for (int i = 0; i < n; i++) {
    	if (!used[i]) {
    		int min1 = i;
    		int max1 = i;
    		dfs(i, min1, max1);

    		comp.push_back(make_pair(min1, max1));
    	}
    }

    int ans = 0;
    int now = -1;

    for (int i = 0; i < comp.size(); i++) {
    	if (comp[i].first < now) {
    		ans++;
    	}
    	now = max(now, comp[i].second);
    }

    cout << ans;
}