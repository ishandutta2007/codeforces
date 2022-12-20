#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        ll color[n];
        for (int i = 0; i < n; i++) color[i] = -1;

        ll currid = 1;
        for (ll p : primes) {
            bool used = false;
            for (int i = 0; i < n; i++) {
                if (a[i] % p == 0 && color[i] == -1) {
                    used = true;
                    color[i] = currid;
                }
            }
            if (used) currid++;
        }

        cout << currid-1 << endl;
        for (int i = 0; i < n-1; i++) cout << color[i] << ' ';
        cout << color[n-1] << endl;
    }
}