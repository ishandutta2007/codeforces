#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Station {
    int x, r, f;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<Station> stations(n);
    for (int i = 0; i < n; i++) {
        cin >> stations[i].x >> stations[i].r >> stations[i].f;
    }

    vector<ordered_set> st(10030);
    sort(stations.begin(), stations.end(), [](auto s, auto t){ return s.r > t.r; });
    long long result = 0;
    for (auto s : stations) {
        for (int f = s.f - k; f <= s.f + k; f++) {
            result += st[f + 10].order_of_key(s.x + s.r + 1) - st[f + 10].order_of_key(s.x - s.r);
        }
        st[s.f + 10].insert(s.x);
    }

    cout << result << endl;
    return 0;
}