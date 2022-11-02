#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int a[MAXN], b[MAXN];
int used[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        fill(b, b + n, -1);
        fill(used, used + n + 1, -1);
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            if (used[a[i]] == -1) {
                used[a[i]] = i;
                b[i] = a[i];
            } else {
                arr.push_back(i);
            }
        }
        cout << n - arr.size() << '\n';
        vector<int> lft;
        for (int i = 0; i < n; ++i) {
            if (used[i] == -1) {
                lft.push_back(i);
            }
        }
        while (!arr.empty()) {
            if (arr.back() != lft.back()) {
                b[arr.back()] = lft.back();
            } else {
                b[arr.back()] = a[arr.back()];
                b[used[a[arr.back()]]] = lft.back();
                used[a[arr.back()]] = arr.back();
            }
            arr.pop_back();
            lft.pop_back();
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] + 1 << " ";
        }
        cout << '\n';

    }
    return 0;
}