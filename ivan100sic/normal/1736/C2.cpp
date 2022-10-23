// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct qry {
    int p, v;
    ll sol;
};

struct entry {
    ll val, sumval;
    ll len, sumlen;

    bool operator< (const entry& o) const {
        return val > o.val;  
    }
};

int n;
int a[200005];

int q;
vector<int> qi[200005];
qry u[200005];

int ma[200005];
ll psma[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        a[i] = i+1-x;
    }

    {
        int f = 0;
        for (int i : ra(0, n)) {
            f = max(f, a[i]);
            ma[i] = f;
            psma[i+1] = psma[i] + f;
        }
    }

    cin >> q;
    for (int i : ra(0, q)) {
        int p, v;
        cin >> p >> v;
        p--;
        v = p+1-v;
        u[i] = {p, v, 0ll};
        qi[p].push_back(i);
    }
    
    vector<entry> st;

    // what would be the sum if we pushed h onto the histogram?
    auto histo_solve = [&](int h) -> ll {
        const entry key = {h, 0ll, 0ll, 0ll};
        auto it = R::lower_bound(st, key, less<>{});

        ll totlen = st.size() ? st.back().sumlen : 0ll;

        if (it == st.begin()) {
            return (totlen + 1) * h;
        } else {
            ll z = (it-1)->sumval;
            z += (totlen + 1 - (it-1)->sumlen) * h;
            return z;
        }
    };

    for (int i=n-1; i>=0; i--) {
        // process queries here
        for (int j : qi[i]) {
            auto& [p, v, sol] = u[j];
            
            int w = p == 0 ? 0 : ma[p-1];
            w = max(w, v);
            
            sol = histo_solve(w) + psma[p];
        }

        // insert into histogram
        ll len = 1, val = a[i];

        while (st.size() && st.back().val < val) {
            len += st.back().len;
            st.pop_back();
        }

        ll sumval = val * len + (st.size() ? st.back().sumval : 0ll);
        ll sumlen = len + (st.size() ? st.back().sumlen : 0ll);

        st.push_back({val, sumval, len, sumlen});
    }

    for (int i : ra(0, q)) {
        cout << n*(n+1ll) / 2 - u[i].sol << '\n';
    }
}