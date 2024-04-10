#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3;
int arr[maxn];

main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = arr[i + 1] - arr[i];
    }
    vector<int> ansarr;
    for (int ans = 1; ans <= n; ++ans) {
        int f = true;
        for (int s = 0; s < ans && f; ++s) {
            int x = arr[s];
            for (int i = s; i < n; i += ans) {
                if (arr[i] != x) {
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            ansarr.push_back(ans);
        }
    }
    cout << ansarr.size() << endl;
    for (auto elem : ansarr) {
        cout << elem << " ";
    }
    return 0;
}