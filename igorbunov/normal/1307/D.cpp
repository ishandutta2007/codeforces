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

 
//#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;

#define int long long
#define endl "\n"

vector<int> g[200000];
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> sp(k);

    for (int i = 0; i < k; i++) {
    	int ind;
    	cin >> ind;
    	sp[i] = ind - 1;
    }

    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }



    vector<int> d1(n, 10000000LL);
    d1[0] = 0;
    queue<int> q;
    q.push(0);
    vector<bool> used(n);
    while (q.size() != 0) {
    	int v = q.front();
    	q.pop();
    	used[v] = true;

    	for (auto u: g[v]) {
    		if (!used[u]) {
    			d1[u] = min(d1[u], d1[v] + 1);
    			q.push(u);
    		}
    	}
    }


    vector<int> d2(n, 10000000LL);
    d2[n - 1] = 0;
    q.push(n - 1);

    for (int i = 0; i < n; i++) {
    	used[i] = false;
    }
    while (q.size() != 0) {
    	int v = q.front();
    	q.pop();
    	used[v] = true;

    	for (auto u: g[v]) {
    		if (!used[u]) {
    			d2[u] = min(d2[u], d2[v] + 1);
    			q.push(u);
    		}
    	}
    }

    /*for (int i = 0; i < n; i++) {
    	cout << d1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
    	cout << d2[i] << " ";
    }

    cout << endl;*/

    vector<int> sd = d1;
	vector<int> ed = d2;
	sort(sp.begin(), sp.end(), [&](int i, int j) {
		return sd[i] < sd[j];
	});
	multiset<int> es;
	for (auto t : sp) {
		es.insert(ed[t]);
	}
	int ans = 0;
	for (auto t : sp) {
		es.erase(es.find(ed[t]));
		if (!es.empty()) ans = max(ans, 1 + sd[t] + *es.rbegin());
	}
	ans = min(ans, sd[n - 1]);
	cout << ans << '\n';
}