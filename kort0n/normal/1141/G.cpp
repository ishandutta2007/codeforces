#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n, k;
vector<l_l> pathes[200500];
ll parent[200050];
ll color[200050];
ll ans;

void bfs(int from, int used) {
    int NEXT = 1;
    if(used == 1) NEXT++;
    for(int i = 0; i < pathes[from].size(); i++) {
        int to = pathes[from][i].first;
        if(to == parent[from]) continue;
        if(NEXT > ans) NEXT = 1;
        color[pathes[from][i].second] = NEXT;
        parent[to] = from;
        bfs(to, NEXT);
        NEXT++;
        if(NEXT == used) NEXT++;
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pathes[x].push_back({y, i});
        pathes[y].push_back({x, i});
    }
    ll ok = n;
    ll ng = 0;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        ll over = 0;
        for(int i = 1; i <= n; i++) {
            if(pathes[i].size() > mid) over++;
        }
        if(over <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    ans = ok;
    bfs(1, -1);
    for(int i = 1; i < n; i++) cout << color[i] << " ";
    cout << endl;
    return 0;
}