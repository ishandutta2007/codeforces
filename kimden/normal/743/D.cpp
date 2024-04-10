#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 200203;
const ll MIN = -1000000000000000LL;
vector<int> g[MAXN];
ll max_sum[MAXN];
ll sum[MAXN];
ll a[MAXN];
ll ans;
ll n;

void dfs(int v, int p){
    int u;
    sum[v] = 0;
    ll aa = MIN, bb = MIN, x;
    for(int i = 0; i < g[v].size(); i++){
        u = g[v][i];
        if(u == p){
            continue;
        }
        dfs(u, v);
        sum[v] += sum[u];
        x = max_sum[u];
        if(x > bb){
            bb = x;
        }
        if(aa < bb){
            swap(aa, bb);
        }
    }
    sum[v] += a[v];
    ans = max(ans, aa + bb);
    max_sum[v] = max(aa, sum[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int u, v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    ans = MIN;
    for(int i = 0; i < n + 1; i++){
        if(i == n){
            cout << "Impossible" << endl;
            return 0;
        }
        if(g[i].size() >= 3 || (i == 0 && g[i].size() >= 2)){
            break;
        }
    }
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}