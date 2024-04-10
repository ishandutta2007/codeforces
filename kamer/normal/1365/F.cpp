#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll BIG = 3000000000;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) cin >> b[i];
        multiset<ll> as, bs;
        for (int i = 0; i < n / 2; i++) {
            as.insert(min(a[i], a[n - i - 1]) * BIG + max(a[i], a[n - i - 1]));

            bs.insert(min(b[i], b[n - i - 1]) * BIG + max(b[i], b[n - i - 1]));
        }

        if (as != bs) {
            cout << "No\n";
        } else {
            if (n % 2 == 1) {
                if  (a[n / 2] != b[n / 2]) cout << "No\n";
                else cout << "Yes\n";
            } else cout << "Yes\n";
        }

    }
}