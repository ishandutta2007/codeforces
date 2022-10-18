#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin >> n >> r;
    long long k;
    cin >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (r >= n - 1) {
        cout << k + accumulate(a.begin(), a.end(), 0LL) << endl;
        return 0;
    }
    
    long long L = 0; // possible
    long long R = k + accumulate(a.begin(), a.end(), 0LL) + 1; // not possible
    vector<long long> additional(n, 0);
    while (L + 1 < R) {
        long long M = (L + (R - L) / 2);
        long long avail = k;
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i];
            if (i > 2*r) {
                cur -= a[i - 2*r - 1];
                cur -= additional[i - 2*r - 1];
            }
            // handle i-r
            if (i >= r) {
                if (cur < M) {
                    avail -= M - cur;
                    additional[i] = M - cur;
                    cur = M;
                } else {
                    additional[i] = 0;
                }
            }
            if (avail < 0) break;
        }
        for (int i = n; i < n + r; i++) {
            if (i > 2*r) {
                cur -= a[i - 2*r - 1];
                cur -= additional[i - 2*r - 1];
            }
            if (cur < M) {
                avail -= M - cur;
                cur = M;
            }
            if (avail < 0) break;
        }
        if (avail >= 0)
            L = M;
        else
            R = M;
    }
    cout << L << endl;
}