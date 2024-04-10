#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool prime(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        ll x, d;
        cin >> x >> d;
        int k = 0;
        while (x % d == 0) {
            x /= d;
            ++k;
        }
        if (k <= 1) {
            cout << "NO\n";
            continue;
        }
        if (k == 2) {
            cout << (prime(x) ? "NO" : "YES") << "\n";
        } else {
            if (x != 1) {
                if (!prime(x)) {
                    cout << "YES\n";
                } else {
                    if (prime(d)) {
                        cout << "NO\n";
                        continue;
                    }
                    int a = 0;
                    while (d % x == 0) {
                        ++a;
                        d /= x;
                    }

                    cout << ((d > 1 || (a - 1) * (k - 1) >= a + 1) ? "YES" : "NO") << "\n";
                }
            } else {
                cout << (prime(d) ? "NO" : "YES") << "\n";
            }
        }
    }

}