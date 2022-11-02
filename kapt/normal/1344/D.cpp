#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int n, k;
const int MAXN = 2e5;
int a[MAXN], b[MAXN];

bool check(int x) {
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        int l = -1, r = a[i];
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[i] - 3 * m * m - 3 * m - 1 >= x) {
                l = m;
            } else {
                r = m;
            }
        }
        b[i] = l + 1;
        sm += b[i];
    }
    return sm >= k;
}

main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = -5e18, r = 2e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    check(l);
    vector<int> can; int sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += b[i];
        b[i]--;
        if (a[i] - 3 * b[i] * b[i] - 3 * b[i] - 1 == l) {
            can.push_back(i);
        }
        b[i]++;
    }
    for (int i = 0; i < sm - k; ++i) {
        b[can[i]]--;
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    return 0;
}