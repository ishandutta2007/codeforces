#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXV = 1e5 + 1;

    int N;
    cin >> N;

    int ans = 0;
    set<pair<int, int>> ct;

    vector<int> colors(N);
    vector<int> colct(MAXV);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
        ct.erase({ colct[colors[i]], colors[i] });
        ct.insert({ ++colct[colors[i]], colors[i] });

        bool ok = false;

        if (ct.size() == 1) ok = true;
        else {
            if (ct.begin()->first == 1 &&
                    next(ct.begin())->first == ct.rbegin()->first)
                ok = true;

            if (ct.rbegin()->first == ct.begin()->first + 1 &&
                    next(ct.rbegin())->first == ct.begin()->first)
                ok = true;
        }

        if (ok) ans = max(ans, i + 1);
    }

    cout << ans << endl;

    return 0;
}