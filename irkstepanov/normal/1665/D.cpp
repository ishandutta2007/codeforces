#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

vector<int> primes = {5, 7, 11, 13, 17, 19, 23, 29};

ll rev(ll a, ll p) {
    ll n = p - 2;
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a;
            ans %= p;
        }
        a *= a;
        a %= p;
        n >>= 1;
    }
    return ans;
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

    ll p = 1;
    for (int x : primes) {
        p *= x;
    }

    while (tt--) {
        vector<ll> g(30);
        for (int i = 1; i <= 29; ++i) {
            cout << "? " << i << " " << p + i << endl;
            cin >> g[i];
        }
        vector<int> r(30);
        for (int x : primes) {
            for (int i = 1; i <= 29; ++i) {
                if (g[i] % x == 0) {
                    r[x] = -i % x;
                    r[x] += x;
                    r[x] %= x;
                    break;
                }
            }
        }
        ll ans = 0;
        for (int x : primes) {
            ll val = 1;
            for (int y : primes) {
                if (y != x) {
                    val *= y;
                }
            }
            ans += val * r[x] * rev(val, x);
            ans %= p;
        }
        if (ans == 0) {
            ans += p;
        }
        cout << "! " << ans << "\n";
    }

}