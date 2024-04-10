#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 1.5e7 + 100;

int mind[nmax];
int cnt[nmax];
vector<int> primes;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < nmax; ++i) {
        mind[i] = i;
    }

    for (int i = 2; i < nmax; ++i) {
        if (mind[i] == i) {
            primes.pb(i);
        }
        for (int p : primes) {
            if (p * i >= nmax || p > mind[i]) {
                break;
            }
            mind[p * i] = p;
        }
    }


    int n;
    cin >> n;
    int g = 0;
    vector<int> vals;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        g = __gcd(g, a);
        vals.pb(a);
    }

    for (int i = 0; i < n; ++i) {
        int a = vals[i] / g;
        while (a != 1) {
            int d = mind[a];
            if (mind[a / d] == d) {
                a /= d;
                continue;
            }
            ++cnt[d];
            a /= d;
        }
    }

    int ans = n;

    for (int p : primes) {
        if (cnt[p] == n || cnt[p] == 0) {
            continue;
        }
        ans = min(ans, n - cnt[p]);
    }

    cout << (ans == n ? -1 : ans) << "\n";

}