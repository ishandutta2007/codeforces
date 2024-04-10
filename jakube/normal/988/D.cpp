#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<long long> s(v.begin(), v.end());
    
    vector<long long> best = {v[0]};
    for (long long start : v) {
        for (int d = 0; d < 33; d++) {
            long long x = start + (1LL << d);
            if (s.count(x)) {
                if (best.size() == 1) {
                    best = {start, x};
                }
                x += (1LL << d);
                if (s.count(x)) {
                    best = {start, start + (1LL << d), x};
                    break;
                }
            }
        }
        if (best.size() == 3)
            break;
    }

    cout << (int)best.size() << '\n';
    for (auto x : best) {
        cout << x << ' ';
    }
    cout << '\n';
}