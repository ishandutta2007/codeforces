#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        while (i < n && i < k && a[i] < b[n-1-i]) {
            swap(a[i], b[n-1-i]);
            i++;
        }
        cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    }
}