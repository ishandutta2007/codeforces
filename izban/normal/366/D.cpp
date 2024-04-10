#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1 << 10;
const int maxm = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

vector<pair<int, pair<int, int> > > e[maxn];

int n, m;
//set<pair<int, int> > st;
int d[maxn];

/*int dijkstra(int mn) {
    memset(d, 0, sizeof(d));
    d[1] = -inf;
    for (int i = 1; i <= n; i++) st.insert(make_pair(d[i], i));
    
    while (!st.empty()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        if (d[v] == 0) continue;
        for (int i = 0; i < e[v].size(); i++) if (e[v][i].second.first <= mn && e[v][i].second.first <= -d[v]) {
            if (d[e[v][i].first] > max(d[v], -e[v][i].second.second)) {
                st.erase(make_pair(d[e[v][i].first], e[v][i].first));
                d[e[v][i].first] = max(d[v], -e[v][i].second.second);
                st.insert(make_pair(d[e[v][i].first], e[v][i].first));
            }
        }
    }
    return -d[n];
}*/

bool bfs(int mn, int mx) {
    memset(d, 0, sizeof(d));
    d[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < e[v].size(); i++) if (e[v][i].second.first <= mn && e[v][i].second.second >= mx && !d[e[v][i].first]) {
            d[e[v][i].first] = 1;
            q.push(e[v][i].first);
        }
    }
    return d[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) e[i].clear();
        set<int> V;
        for (int i = 0; i < m; i++) {
            int a, b, l, r;
            cin >> a >> b >> l >> r;
            V.insert(l);
            V.insert(r);
            e[a].push_back(make_pair(b, make_pair(l, r)));
            e[b].push_back(make_pair(a, make_pair(l, r)));            
        }
        vector<int> v;
        for (set<int>::iterator it = V.begin(); it != V.end(); it++) v.push_back(*it);
        
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            int l = i - 1, r = v.size() - 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (bfs(v[i], v[m])) l = m;
                else r = m;
            }
            int m = bfs(v[i], v[r]) ? r : l;
            if (m >= i) 
                ans = max(ans, v[m] - v[i] + 1);
        }
        if (!ans) cout << "Nice work, Dima!" << endl;
        else cout << ans << endl;
    }
    
	return 0;
}