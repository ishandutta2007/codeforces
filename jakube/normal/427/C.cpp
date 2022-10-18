#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;
vector<vector<int>> pre;

void dfs1(int node)
{
    if (visited[node])
        return;
    visited[node] = true;

    for (const auto& next : pre[node])
    {
        dfs1(next);
    }

    order.push_back(node);
}

vector<vector<int>> scc;

bool dfs2(int node)
{
    if (visited[node])
        return false;
    visited[node] = true;
    scc.back().push_back(node);

    for (const auto& next : adj[node])
    {
        dfs2(next);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> costs(n);
    FOR(i, n) cin >> costs[i];
    adj = vector<vector<int>>(n);
    pre = vector<vector<int>>(n);
    visited = vector<bool>(n, false);

    int m;
    cin >> m;
    FOR(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        pre[v].push_back(u);
    }


    FOR(i, n)
    {
        dfs1(i);
    }

    visited = vector<bool>(n, false);

    reverse(ALL(order));
    for (const auto& i : order)
    {
        scc.push_back(vector<int>());
        if (!dfs2(i))
            scc.pop_back();
    }

    lint total_cost = 0;
    lint cnt = 1;
    for (auto i : scc)
    {
        transform(ALL(i), i.begin(), [&costs](int j){return costs[j];});
        int mi = *min_element(ALL(i));
        total_cost += mi;
        cnt = (cnt * count(ALL(i), mi)) % MOD;
    }

    cout << total_cost << endl;
    cout << cnt;
}