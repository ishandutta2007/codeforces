#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool cmp(array<int, 2> a, array<int, 2> b) {
    return a[0] + a[1] > b[0] + b[1];
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector<array<int, 2>> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i][0] >> arr[i][1];
        }
        if (arr[0][0] >= k) {
            cout << "YES" << '\n';
            continue;
        }
        if (arr[0][0] + arr[0][1] < k) {
            cout << "NO" << '\n';
            continue;
        }
        k -= arr[0][1];
        arr[0] = {-1, -1};
        sort(arr.begin(), arr.end(), cmp);
        bool f = false;
        set<array<int, 2>> st_b;
        multiset<int> st_dif;
        for (int i = 0; i < n - 1; ++i) {
            int a = arr[i][0], b = arr[i][1];
            if (a >= k) {
                f = true;
                break;
            }
            if (a + b >= k) {
                int rem = a + b - k;
                k -= b;
                while (!st_b.empty()) {
                    auto it = st_b.end();
                    it--;
                    if ((*it)[0] > rem) {
                        int j = (*it)[1];
                        st_b.erase(it);
                        st_dif.erase(st_dif.lower_bound(arr[j][0] - arr[j][1]));
                    } else {
                        break;
                    }
                }
                st_b.insert({b, i});
                st_dif.insert(a - b);
                auto it = st_dif.end();
                it--;
                if ((*it) >= k) {
                    f = true;
                    break;
                }
            }
        }
        if (f) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}