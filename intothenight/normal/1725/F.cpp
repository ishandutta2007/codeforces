#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
    constexpr int B = 30;
    vector<int> ans(B + 1);

    for (int b = 0; b <= B; b++) {
        int full = 0, w = 1 << b;
        vector<array<int, 2>> sweep;
        for (int i = 0; i < N; i++) {
            int S = R[i] - L[i] + 1;
            if (S >= w) {
                full++;
            } else {
                int l = L[i] % w;
                int r = R[i] % w;
                if (l <= r) {
                    sweep.push_back({l, 0});
                    sweep.push_back({r, 1});
                } else {
                    sweep.push_back({0, 0});
                    sweep.push_back({r, 1});
                    sweep.push_back({l, 0});
                }
            }
        }
        int cur = 0, best = 0;
        sort(begin(sweep), end(sweep));
        for (auto [i, s] : sweep) {
            if (s == 0) {
                cur++;
                best = max(best, cur);
            } else if (s == 1) {
                cur--;
            }
        }
        ans[b] = full + best;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int w;
        cin >> w;
        w = __builtin_ctz(w);
        cout << ans[w] << '\n';
    }

    return 0;
}