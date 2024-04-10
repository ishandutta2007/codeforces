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

    ll n;
    cin >> n;
    ll tf = 0;
    ll f = 0;
    ll h = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x == 25) {
            tf++;
            continue;
        }
        if (x == 50) {
            if (tf == 0) {
                cout << "NO" << endl;
                return 0;
            }
            tf--;
            f++;
        }
        if (x == 100) {
            if (f == 0) {
                if (tf < 3) {
                    cout << "NO" << endl;
                    return 0;
                }
                tf -= 3;
                h++;
            } else {
                if (tf == 0) {
                    cout << "NO" << endl;
                    return 0;
                }
                f--;
                tf--;
                h++;
            }
        }
    }
    cout << "YES" << endl;
}