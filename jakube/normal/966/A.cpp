#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vector<int> l(cl);
    for (int i = 0; i < cl; i++) {
        cin >> l[i];
    }
    vector<int> e(ce);
    for (int i = 0; i < ce; i++) {
        cin >> e[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long time = std::numeric_limits<long long>::max();
        if (x1 == x2) {
            time = min(time, abs(y2 - y1));
        }

        if (ce) {
            // elevator after
            auto it = lower_bound(e.begin(), e.end(), y1);
            if (it != e.end()) {
                int ye = *it;
                time = min(time, abs(ye - y1) + abs(ye - y2) + (abs(x2 - x1) + v - 1) / v);
            }

            // elevator before
            if (it != e.begin()) {
                --it;
                int ye = *it;
                time = min(time, abs(ye - y1) + abs(ye - y2) + (abs(x2 - x1) + v - 1) / v);
            }
        }

        if (cl) {
            // stairs after
            auto it = lower_bound(l.begin(), l.end(), y1);
            if (it != e.end()) {
                int ye = *it;
                time = min(time, abs(ye - y1) + abs(ye - y2) + abs(x2 - x1));
            }

            // stairs before
            if (it != l.begin()) {
                --it;
                int ye = *it;
                time = min(time, abs(ye - y1) + abs(ye - y2) + abs(x2 - x1));
            }
        }

        cout << time << '\n';
    }
    
}