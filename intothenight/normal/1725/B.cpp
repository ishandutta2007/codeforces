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
    int64_t D;
    cin >> N >> D;
    vector<int64_t> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    sort(rbegin(P), rend(P));
    int64_t ans = 0;
    int l = 0, r = N - 1;
    while (l <= r) {
        int64_t each = P[l++], sum = each;
        while (l <= r && sum <= D) {
            sum += each, r--;
        }
        ans += sum > D;
    }
    cout << ans << '\n';
    return 0;
}