#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<ll> pref(n + 1, (ll) 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i] - b[i];
        }

        vector<tuple<int, int>> segs(m);

        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            segs[i] = { l, r };
        }

        if (pref[n] != (ll) 0) {
            cout << "NO\n";
            continue;
        }

        vector<vector<int>> endpoint_segs(n + 1, vector<int>());

        for (int i = 0; i < m; i++) {
            auto [l, r] = segs[i];
            endpoint_segs[l].emplace_back(i);
            endpoint_segs[r].emplace_back(i);
        }

        vector<int> seg_count(m, 0);
        set<int> non_zero_entries;

        queue<tuple<int, int>> zero_segs;

        for (int i = 0; i <= n; i++) {
            if (pref[i] == 0) {
                for (auto seg : endpoint_segs[i]) {
                    seg_count[seg]++;
                    if (seg_count[seg] == 2) {
                        zero_segs.push(segs[seg]);
                    }
                }
            } else {
                non_zero_entries.insert(i);
            }
        }

        while (!zero_segs.empty()) {
            auto [l, r] = zero_segs.front();
            zero_segs.pop();

            auto it = non_zero_entries.lower_bound(l);
            auto it_end = non_zero_entries.upper_bound(r);
            while (it != it_end) {
                auto val = *it;
                for (auto seg : endpoint_segs[val]) {
                    seg_count[seg]++;
                    if (seg_count[seg] == 2) {
                        zero_segs.push(segs[seg]);
                    }
                }
                it = non_zero_entries.erase(it);
                pref[val] = 0;
            }
        }

        bool is_zero = true;
        for (int i = 0; i <= n; i++) {
            if (pref[i] != (ll) 0) {
                is_zero = false;
                break;
            }
        }

        if (is_zero) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}