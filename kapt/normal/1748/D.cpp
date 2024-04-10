#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int a, b, d;
        cin >> a >> b >> d;
        vector<array<int, 2>> add;
        int cnt = 0;
        while (d % 2 == 0) {
            d /= 2;
            cnt++;
        }
        if (a % (1 << cnt) != 0 || b % (1 << cnt) != 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < 30; ++i) {
            if ((a & (1 << i)) == (b & (1 << i))) continue;
            if (a & (1 << i)) {
                add.push_back({-(1 << i), i});
            } else {
                add.push_back({(1 << i), i});
            }
        }
        for (auto &elem : add) {
            elem[0] = (elem[0] % d + d) % d;
        }
        int k = add.size() / 2;
        unordered_map<int, int> used;
        for (int mask = 0; mask < (1 << k); ++mask) {
            int sum = 0;
            for (int i = 0; i < k; ++i) {
                if (mask & (1 << i)) {
                    sum += add[i][0];
                    sum %= d;
                }
            }
            used[sum] = mask;
        }
        int ans = -1;
        for (int mask = 0; mask < (1 << (add.size() - k)); ++mask) {
            int sum = b - a;
            for (int i = k; i < add.size(); ++i) {
                if (mask & (1 << (i - k))) {
                    sum -= add[i][0];
                }
            }
            sum = (sum % d + d) % d;
            if (used.count(sum)) {
                ans = used[sum] + (mask << k);
                break;
            }
        }
        if (ans == -1) {
            cout << -1 << endl;
            continue;
        }
        int x = 0;
        for (int i = 0; i < 30; ++i) {
            if (ans & (1 << i)) {
                x |= (1 << add[i][1]);
            }
        }
        int r = (a | x) % d;
        r = (d - r) % d;
        int val = (d + 1) / 2;
        for (int i = 0; i < 30; ++i) {
            r = (r * val) % d;
        }
        x |= (r << 30);
        cout << x << endl;
    }
    return 0;
}