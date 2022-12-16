#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n; i++) {
            if (k == 0 || i == n-1) cout << a[i] << ' ';
            else {
                int amt = min(k, a[i]);
                a[i] -= amt;
                a[n-1] += amt;
                k -= amt;
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
}