#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<vector<int>> g;
vector<ll> sumodd, cntodd, sumeven, cnteven;
ll ans = 0;

void dfs(int v, int prv = -1){
    for(auto u: g[v]){
        if(u != prv){
            dfs(u, v);
            sumodd[v] += sumeven[u] + cnteven[u];
            cntodd[v] += cnteven[u];
            sumeven[v] += sumodd[u] + cntodd[u];
            cnteven[v] += cntodd[u];
        }
    }
    ll so = sumodd[v], co = cntodd[v], se = sumeven[v], ce = cnteven[v];
    for(auto u: g[v]){
        if(u != prv){
            /// Odd paths
            // OE
            ans += ((sumeven[u] + cnteven[u]) * (ce - cntodd[u]) + (se - sumodd[u] - cntodd[u]) * cnteven[u] + (ce - cntodd[u]) * cnteven[u]) / 2;
            // EO
            ans += ((sumodd[u] + cntodd[u]) * (co - cnteven[u]) + (so - sumeven[u] - cnteven[u]) * cntodd[u] + (co - cnteven[u]) * cntodd[u]) / 2;
            /// Even paths
            // EE
            ans += ((sumodd[u] + cntodd[u]) * (ce - cntodd[u]) + (se - sumodd[u] - cntodd[u]) * cntodd[u]) / 2;
            // OO
            ans += ((sumeven[u] + cnteven[u]) * (co - cnteven[u]) + (so - sumeven[u] - cnteven[u]) * cnteven[u]) / 2;
            se -= sumodd[u] + cntodd[u];
            ce -= cntodd[u];
            so -= sumeven[u] + cnteven[u];
            co -= cnteven[u];
        }
    }
    ans += (sumodd[v] + cntodd[v]) / 2;
    ans += (sumeven[v]) / 2;
    ++cnteven[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    g.resize(n);
    sumodd.resize(n, 0);
    cntodd.resize(n, 0);
    sumeven.resize(n, 0);
    cnteven.resize(n, 0);
    int u, v;
    for(int i = 0; i < n - 1; ++i){
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout << ans << endl;
}