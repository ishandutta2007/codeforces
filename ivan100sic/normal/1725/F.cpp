// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, l[100005], r[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;

    for (int i : ra(0, n)) {
        cin >> l[i] >> r[i];
    }

    map<int, int> sol;

    for (int w=1; w<=(1<<29); w<<=1) {
        vector<pair<int, int>> mp;
        int cnt = 0, best = 0;

        for (int i : ra(0, n)) {
            if (r[i] - l[i] + 1 >= w) {
                cnt++;
            } else {
                int le = l[i] % w;
                int re = le + (r[i] - l[i]);

                mp.emplace_back(le, 1);
                mp.emplace_back(re+1, -1);
                mp.emplace_back(le+w, 1);
                mp.emplace_back(re+1+w, -1);
            }
        }

        R::sort(mp);
        best = cnt;
        for (auto [x, d] : mp) {
            cnt += d;
            best = max(best, cnt);
        }

        sol[w] = best;
    }

    int q;
    cin >> q;
    while (q--) {
        int w;
        cin >> w;
        cout << sol[w & -w] << '\n';
    }
}