#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long l = 0, r = (long long) 1e15;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        long long cnt = (m - 1) / 2 + (m - 4) / 4;
        if (cnt >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}