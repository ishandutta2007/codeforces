#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int64_t a[n];
        for (int i = 0; i < n; i++) cin >> a[i];


        int64_t used[100];
        int64_t powers[100];
        powers[0] = 1;
        used[0] = false;
        for (int i = 1; i < 100; i++) {
            used[i] = false;
            if (powers[i-1] <= 1e16) {
                powers[i] = k*powers[i-1];
            } else {
                powers[i] = powers[i-1];
            }
        }
        sort(a, a+n);

        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = 99; j >= 0; j--) {
                if (used[j]) continue;
                if (powers[j] <= a[i]) {
                    a[i] -= powers[j];
                    used[j] = true;
                }
            }
            if (a[i] > 0) {
                cout << "NO" << endl;
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
        }
    }
}