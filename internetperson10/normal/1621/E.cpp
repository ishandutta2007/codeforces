#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll BIG = -111234567890;

struct SegTree {
    ll lx, rx, val, op;
    SegTree *ls, *rs;
    SegTree(int l, int r) {
        lx = l;
        rx = r;
        val = 0;
        op = 0;
        if(r - l > 1) {
            int mid = (l + r)/2;
            ls = new SegTree(l, mid);
            rs = new SegTree(mid, r);
        }
        else {
            ls = rs = nullptr;
        }
    }
    ~SegTree() {
        delete ls;
        delete rs;
    }
    void prop() {
        if(ls == nullptr) return;
        ls->op += op;
        ls->val += op;
        rs->op += op;
        rs->val += op;
        op = 0;
    }
    void add(int l, int r, int x) {
        prop();
        if(lx >= r || l >= rx) return;
        if(l <= lx && rx <= r) {
            val += x;
            op += x;
            return;
        }
        ls->add(l, r, x);
        rs->add(l, r, x);
        val = min(ls->val, rs->val);
    }
    ll size() {
        return rx - lx;
    }
};

ll div_up(ll n, ll x) {
    return (n+x-1)/x;
}

ll best_bit(int n) {
    int g = 1;
    while(g <= n) g *= 2;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    SegTree st(0, best_bit(100000));
    while(t--) {
        int n, m;
        cin >> m >> n;
        vector<ll> teachers(m);
        vector<vector<ll>> students(n);
        vector<ll> sum(n);
        for(int i = 0; i < m; i++) {
            cin >> teachers[i];
        }
        sort(teachers.rbegin(), teachers.rend());
        for(int i = 0; i < n; i++) {
            st.add(teachers[i], st.size(), -1);
        }
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            students[i].resize(x);
            for(int j = 0; j < x; j++) {
                cin >> students[i][j];
                sum[i] += students[i][j];
            }
            ll avg = div_up(sum[i], x);
            st.add(avg, st.size(), 1);
        }
        for(int i = 0; i < n; i++) {
            for(int g : students[i]) {
                ll old_avg = div_up(sum[i], students[i].size());
                ll new_avg = div_up(sum[i] - g, students[i].size()-1);
                st.add(old_avg, st.size(), -1);
                st.add(new_avg, st.size(), 1);
                cout << (st.val >= 0);
                st.add(old_avg, st.size(), 1);
                st.add(new_avg, st.size(), -1);
            }
        }
        cout << '\n';
        for(int i = 0; i < n; i++) {
            st.add(teachers[i], st.size(), 1);
        }
        for(int i = 0; i < n; i++) {
            st.add(div_up(sum[i], students[i].size()), st.size(), -1);
        }
    }
}