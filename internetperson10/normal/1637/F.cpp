#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<ll> ct, val;
vector<bool> taken;

int dfs(int x, int par = -1) {
    if(par != -1) {
        int ma = 0;
        for(auto ch : adj[x]) {
            if(ch == par) continue;
            ma = max(ma, dfs(ch, x));
        }
        val[x] = max(0LL, ct[x] - ma);
        ma = max(ma, (int)ct[x]);
        return ma;
    }
    else {
        vector<ll> v;
        for(auto ch : adj[x]) {
            v.push_back(dfs(ch, x));
        }
        sort(v.rbegin(), v.rend());
        if(v.size() == 1) val[x] = (max(0LL, 2 * ct[x] - v[0]));
        else val[x] = (max(0LL, ct[x] - v[0]) + max(0LL, ct[x] - v[1]));
        return v[0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) {
        int n;
        cin >> n;
        if(n == 2) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << 2LL * max(a, b) << '\n';
            break;
        }
        adj.resize(n);
        ct.resize(n);
        val.resize(n);
        taken.resize(n);
        for(int i = 0; i < n; i++) cin >> ct[i];
        for(int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int best = -1, root = -1;
        for(int i = 0; i < n; i++) {
            if(best < ct[i]) {
                root = i;
                best = ct[i];
            }
        }
        dfs(root);
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            //cout << val[i] << ' ';
            ans += val[i];
        }
        cout << ans << '\n';
    }
}