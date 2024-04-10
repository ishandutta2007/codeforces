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
        ll bst = 1;
        for (ll i = 1; i <= sqrt(n)+3; i++) {
            if (n % i == 0) {
                if (i <= k) bst = max(bst, i);
                if (n/i <= k) bst = max(bst, n/i);
            }
        }

        cout << n/bst << endl;
    }
}