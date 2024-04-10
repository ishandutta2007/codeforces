#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<int> le, ri, parent, leaves, dep;
vector<vector<int>> anser;

struct SegTree {
    int lx, rx, val = 0, op = 0;
    SegTree *ls;
    SegTree *rs;
    SegTree(int l, int r) {
        lx = l; rx = r;
        if(rx - lx == 1) {
            ls = nullptr;
            rs = nullptr;
            if(lx >= leaves.size()) return;
            val = dep[leaves[lx]];
            return;
        }
        int midx = (lx + rx)/2; 
        ls = new SegTree(lx, midx);
        rs = new SegTree(midx, rx);
        val = std::max(ls->val, rs->val);
    }
    // Operations:
    // prop() propagates op
    // max() finds a node with the most nodes taken and returns it
    // sub(l, r) decrements everything in range [l, r)
    void prop() {
        if(ls == nullptr) {
            op = 0;
            return;
        }
        ls->op += op;
        ls->val += op;
        rs->op += op;
        rs->val += op;
        op = 0;
    }
    pair<int, int> max() {
        prop();
        // cout << lx << ' ' << rx << ' ' << val << '\n';
        if(ls == nullptr) return {lx, val};
        auto p1 = ls->max();
        if(p1.second == val) return p1;
        auto p2 = rs->max();
        if(p2.second == val) return p2;
        return {-1, -1};
    }
    void sub(int l, int r) {
        prop();
        if(l >= rx || lx >= r) return;
        if(l <= lx && rx <= r) {
            op--;
            val--;
            return;
        }
        // cout << "Yay!\n";
        ls->sub(l, r);
        rs->sub(l, r);
        val = std::max(ls->val, rs->val);
        // cout << '\n' << lx << ' ' << rx << ' ' << val << '\n';
    }
};

int dfs(int n, int k = 0, int par = -1) {
    parent[n] = par;
    dep[n] = k;
    if(adj[n].size() == 1 && n != 0) {
        le[n] = leaves.size();
        ri[n] = leaves.size();
        leaves.push_back(n);
        return 0;
    }
    int ans = 0;
    for(int ch : adj[n]) {
        if(ch == par) continue;
        ans += dfs(ch, k+1, n);    
        le[n] = min(le[n], le[ch]);
        ri[n] = max(ri[n], ri[ch]);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    adj.resize(n);
    anser.resize(n);
    le.resize(n, n+1);
    ri.resize(n, -1);
    parent.resize(n);
    dep.resize(n);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int l = 0;
    for(int i = 1; i < n; i++) {
        if(adj[i].size() == 1) l++;
    }
    if(k >= l) {
        k = min(k, max(n/2, l));
        cout << (ll)(n-k)*(ll)(k) << '\n';
        return 0;
    }
    if(n == 2) {
        cout << 1 << '\n';
        return 0;
    }
    dfs(0);
    int g = 1;
    while(g < l) g *= 2; 
    SegTree st(0, g);
    int ans = 0;
    for(int i = 0; i < k; i++) {
        auto pa = st.max();
        pa.first = leaves[pa.first];
        // cout << "Res: " << pa.first << ' ' << pa.second << '\n';
        while(pa.second--) {
            ans++;
            pa.first = parent[pa.first];
            // cout << pa.first << ' ' << pa.second << '\n';
            // cout << "Sub: " << le[pa.first] << ' ' << ri[pa.first] << '\n';
            st.sub(le[pa.first], ri[pa.first]+1);
        }
    }
    ll best = 1234567891234567890;
    for(ll i = 0; i <= n - k - ans; i++) {
        best = min(best, (ll)(n - k - i) * (k - i));
    }
    cout << best << '\n';
}