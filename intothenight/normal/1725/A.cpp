#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t N, M;
    cin >> N >> M;
    if (M == 1) {
        cout << N - 1 << '\n';
    } else if (N == 1) {
        cout << M - 1 << '\n';
    } else {
        cout << N * (M - 1) << '\n';
    }
    return 0;
}