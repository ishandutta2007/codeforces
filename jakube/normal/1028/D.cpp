#include <bits/stdc++.h>
using namespace std;

enum Action {
    ADD, ACCEPT
};

int MOD = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<Action, int>> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        v[i] = {s == "ADD" ? ADD : ACCEPT, x};
    }

    long long res = 1;
    set<int> lower, upper, unknown;
    for (auto [action, x] : v) {
        if (action == ADD) {
            if (!lower.empty() && x < *lower.rbegin()) {
                lower.insert(x);
                continue;
            }
            if (!upper.empty() && x > *upper.begin()) {
                upper.insert(x);
                continue;
            }
            unknown.insert(x);
        } else {
            auto it = unknown.find(x);
            if (it != unknown.end()) {
                unknown.erase(it);
                res = 2 * res % MOD;
                for (auto y : unknown) {
                    if (y < x)
                        lower.insert(y);
                    else
                        upper.insert(y);
                }
                unknown.clear();
            } else if (!lower.empty() && x == *lower.rbegin()) {
                lower.erase(lower.find(x));
                for (auto y : unknown) {
                    if (y < x)
                        lower.insert(y);
                    else
                        upper.insert(y);
                }
                unknown.clear();
            } else if (!upper.empty() && x == *upper.begin()) {
                upper.erase(upper.find(x));
                for (auto y : unknown) {
                    if (y < x)
                        lower.insert(y);
                    else
                        upper.insert(y);
                }
                unknown.clear();
            } else {
                res = 0;
                break;
            }
        }
    }

    cout << res * (unknown.size() + 1) % MOD << '\n';
}