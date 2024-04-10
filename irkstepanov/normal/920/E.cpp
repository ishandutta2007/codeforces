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
typedef double ld;
typedef pair<ll, ll> pll;

set<pii> edges;
vector<int> comps;
set<int> unused;
int n;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        ++comps.back();
        q.pop();
        for (set<int>::iterator it = unused.begin(); it != unused.end(); ) {
            set<int>::iterator nx = it;
            ++nx;
            int i = *it;
            if (!edges.count({v, i})) {
                unused.erase(it);
                q.push(i);
            }
            it = nx;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.insert({u, v});
        edges.insert({v, u});
    }

    for (int i = 0; i < n; ++i) {
        unused.insert(i);
    }
    while (!unused.empty()) {
        int v = *unused.begin();
        unused.erase(unused.begin());
        comps.pb(0);
        bfs(v);
    }

    sort(all(comps));
    cout << sz(comps);
    cout << "\n";
    for (int x : comps) {
        cout << x << " ";
    }
    cout << "\n";

}