#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > g(n);
    vector<vector<int> > gr(n);
    vector<int> deg(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[v].pb(u);
        gr[u].pb(v);
        ++deg[u];
    }

    queue<int> q1;
    queue<int> q2;
    vector<bool> inQueue(n, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && deg[i] == 0) {
            q1.push(i);
            inQueue[i] = true;
        }
        if (a[i] == 1 && deg[i] == 0) {
            q2.push(i);
            inQueue[i] = true;
        }
    }

    int ans = 0;
    int done = 0;
    while (done < n) {
        while (!q1.empty()) {
            int v = q1.front();
            ++done;
            q1.pop();
            for (int to : g[v]) {
                --deg[to];
                if (deg[to] == 0) {
                    if (a[to] == 0 && !inQueue[to]) {
                        q1.push(to);
                        inQueue[to] = true;
                    }
                    if (a[to] == 1 && !inQueue[to]) {
                        q2.push(to);
                        inQueue[to] = true;
                    }
                }
            }
        }
        if (q2.empty()) {
            assert(done == n);
            break;
        }
        ++ans;
        while (!q2.empty()) {
            int v = q2.front();
            ++done;
            q2.pop();
            for (int to : g[v]) {
                --deg[to];
                if (deg[to] == 0) {
                    if (a[to] == 0 && !inQueue[to]) {
                        q1.push(to);
                        inQueue[to] = true;
                    }
                    if (a[to] == 1 && !inQueue[to]) {
                        q2.push(to);
                        inQueue[to] = true;
                    }
                }
            }
        }
    }

    cout << ans << "\n";

}