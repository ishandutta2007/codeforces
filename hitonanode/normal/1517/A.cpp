#include <bits/stdc++.h>
using namespace std;

int solve() {
    long long N;
    cin >> N;
    int ret = 0;
    if (N % 2050) return -1;
    auto s = to_string(N / 2050);
    return accumulate(s.begin(), s.end(), 0, [&](int a, char b) { return a + b - '0'; });
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}