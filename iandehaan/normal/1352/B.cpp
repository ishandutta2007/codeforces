#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << "YES" << endl;
            cout << n << endl;
            continue;
        }

        if (n % 2 == 0) {
            if (k % 2 == 0) {
                // even or odd
                if (n < k) {
                    cout << "NO" << endl;
                    continue;
                }
                cout << "YES" << endl;
                for (int i = 0; i < k-1; i++) {
                    cout << 1 << ' ';
                    n--;
                }
                cout << n << endl;
            } else {
                // even
                if (n < 2*k) {
                    cout << "NO" << endl;
                    continue;
                }
                cout << "YES" << endl;
                for (int i = 0; i < k-1; i++) {
                    cout << 2 << ' ';
                    n -= 2;
                }
                cout << n << endl;
            }
        } else {
            if (k % 2 == 0) {
                cout << "NO" << endl;
                continue;
            } else {
                if (n < k) {
                    cout << "NO" << endl;
                    continue;
                }
                cout << "YES" << endl;
                for (int i = 0; i < k-1; i++) {
                    cout << 1 << ' ';
                    n--;
                }
                cout << n << endl;
            }
        }
    }
}