#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<long long>> dp(n+1, vector<long long>(2, 0));

    long long max_so_far = abs(a[1] - a[0]);
    long long cur = max_so_far;
    for (int i = 1; i < n - 1; i++) {
        long long tmp = abs(a[i] - a[i+1]);
        if (i % 2) {
            cur -= tmp;
        }
        else {
            if (cur < 0)
                cur = 0;
            cur += tmp;
            max_so_far = max(max_so_far, cur);
        }
    }

    if (n > 2) {
        cur = abs(a[2] - a[1]);
        max_so_far = max(max_so_far, cur);
        for (int i = 2; i < n - 1; i++) {
            long long tmp = abs(a[i] - a[i+1]);
            if (i % 2 == 0) {
                cur -= tmp;
            } else {
                if (cur < 0)
                    cur = 0;
                cur += tmp;
                max_so_far = max(max_so_far, cur);
            }
        }
    }

    cout << max_so_far << endl;

    return 0;
}