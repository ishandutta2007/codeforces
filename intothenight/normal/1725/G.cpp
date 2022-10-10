#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> small = {0, 3, 5, 7, 8, 9};
    int64_t N;
    cin >> N;
    if (N <= 5) {
        cout << small[N] << '\n';
    } else {
        N -= 6;
        cout << 4 * (N / 3) + (N % 3) + 11 << '\n';
    }
    return 0;
}