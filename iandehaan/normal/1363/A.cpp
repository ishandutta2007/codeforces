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
        int n, x;
        cin >> n >> x;
        int numevens = 0;
        int numodds = 0;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) numevens++;
            else numodds++;
        }

        if (x != n) {
            if (numodds >= 1 && numevens >= 1) {
                    cout << "Yes" << endl;
            } else {
                if (numodds == 0) {
                cout << "No" << endl;
                } else {
                    // num evens == 0
                    if (x % 2 == 0) {
                        cout << "No" << endl;
                    } else {
                        cout << "Yes" << endl;
                    }
                }

            }
        } else {
            if (numodds % 2 == 0) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
}