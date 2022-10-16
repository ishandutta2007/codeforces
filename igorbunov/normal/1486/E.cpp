#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

//#define endl "\n"
//#define int long long


vector<pair<int, int>> g[5100000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int a, b, w;
    	cin >> a >> b >> w;
    	a--;
    	b--;
    	g[a * 51].push_back(make_pair(b * 51 + w, w));
    	g[b * 51].push_back(make_pair(a * 51 + w, w));
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 1; j < 51; j++) {
    		int ind = i * 51 + j;

    		for (auto u: g[i * 51]) {
    			int val = u.second;
    			int where = u.first / 51;
    			int kek = j + val;
    			kek *= kek;
    			kek -= j;
    			g[ind].push_back(make_pair(where * 51, kek));
    		}
    	}
    }

    vector<int> d(5100000, 1000000000);
    d[0] = 0;

    priority_queue <pair<int,int>> q;
	q.push (make_pair (0, 0));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i * 51] == 1000000000) {
			cout << -1 << " ";
		} else {
			cout << d[i * 51] << " ";
		}
	}
	cout << endl;
}