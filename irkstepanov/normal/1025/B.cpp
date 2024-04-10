#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;

void f(ll x, vector<ll>& p) {
    for (ll d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            p.pb(d);
            while (x % d == 0) {
                x /= d;
            }
        }
    }
    if (x != 1) {
        p.pb(x);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    vector<ll> primes;
    f(a[0].first, primes);
    f(a[0].second, primes);

    for (ll p : primes) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i].first % p == 0 || a[i].second % p == 0) {
                continue;
            }
            ok = false;
            break;
        }
        if (ok) {
            cout << p << endl;
            return 0;
        }
    }

    cout << "-1\n";

}