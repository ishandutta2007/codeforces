#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll inf = 1e18;
const ll mod = 1e9 + 7;

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

vector<vector<int> > g;
vector<char> used;
vector<int> ret, tin;
int timer;
int n;
vector<int> st;
vector<vector<int> > components;

void dfs(int v)
{
    used[v] = true;
    tin[v] = ret[v] = timer++;
    st.pb(v);
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
        ret[v] = min(ret[v], ret[to]);
    }
    if (ret[v] == tin[v]) {
        components.pb(vector<int>());
        while (true) {
            components.back().pb(st.back());
            bool finish = (st.back() == v);
            ret[st.back()] = n;
            st.pop_back();
            if (finish) {
                break;
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    g.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
    }

    used.assign(n, false);
    ret.resize(n);
    tin.resize(n);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    ll ans = 1;
    ll sum = 0;

    for (vector<int>& comp : components) {
        ll minn = inf;
        int cnt = 0;
        for (int x : comp) {
            if (minn > a[x]) {
                minn = a[x];
                cnt = 1;
            } else if (minn == a[x]) {
                ++cnt;
            }
        }
        sum += minn;
        mul(ans, cnt);
    }

    cout << sum << " " << ans << "\n";

}