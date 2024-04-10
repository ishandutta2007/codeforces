// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct qry {
    int l, r;
    pair<int, int> ans;
};

int par_to_sgn(int x) {
    return x % 2 ? -1 : 1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        string s;
        cin >> n >> q >> s;
        vector<qry> b(q);
        vector<vector<int>> qids(n);
        for (int i=0; i<q; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            b[i] = {l, r, {-1, -1}};
            qids[l].push_back(i);
        }

        int sum = 0;
        vector<int> sums(n+1);

        map<tuple<int, int, int>, int> loc;

        auto solve_odd = [&loc, &sums](int le, int re) {
            for (int ip : {0, 1}) {
                for (int c : {-1, 1}) { 
                    int d = par_to_sgn(le - ip);
                    int sum_exp = (sums[le] + d*c - sums[re]) * d / 2;
                    auto it = loc.find({sum_exp, ip, c});
                    if (it != loc.end() && it->second < re) {
                        return it->second;
                    }
                }
            }
            // cerr << "error\n";
            return -1;
        };

        for (int l=n-1; l>=0; l--) {
            int sym = s[l] == '+' ? 1 : -1;
            sum = sym - sum;
            sums[l] = sum;
            int pp = l % 2;
            loc[{sum, pp, sym}] = l;

            for (int i : qids[l]) {
                auto& [le, re, ans] = b[i];

                if ((re - le) % 2 == 1) {
                    b[i].ans = {solve_odd(le, re), -1};
                } else {
                    if (sums[le] != sums[re]) {
                        b[i].ans = {solve_odd(le, re-1), re-1};
                    }
                }
            }
        }

        for (int i=0; i<q; i++) {
            auto [u, v] = b[i].ans;
            if (u == -1) {
                cout << "0\n";
            } else if (v == -1) {
                cout << "1\n" << u+1 << '\n';
            } else {
                cout << "2\n" << u+1 << ' ' << v+1 << '\n';
            }
        }
    }
}