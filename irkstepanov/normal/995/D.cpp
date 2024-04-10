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
typedef double ld;

/*int nmax = 6;
vector<int> a(8);
const int inf = 100500;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void rec(int pos) {
    if (pos < 8) {
        for (int i = 0; i < nmax; ++i) {
            a[pos] = i;
            rec(pos + 1);
        }
        return;
    }
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += a[i];
    }
    int maxx = -1, minn = inf;
    for (int b = 0; b  < 3; ++b) {
        for (int z = 0; z < 2; ++z) {
            int s = 0;
            for (int i = 0; i < 8; ++i) {
                if (bit(i, b) == z) {
                    s += a[i];
                }
            }
            maxx = max(maxx, s);
            minn = min(minn, s);
        }

    }
    assert(maxx + minn == sum);
}*/

void print(ll sum, int n) {
    ld ans = ld(sum) / ld(1 << n);
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //rec(0);

    int n, q;
    cin >> n >> q;

    cout << fixed;
    cout.precision(20);

    vector<ll> a(1 << n);
    ll sum = 0;
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
        sum += a[i];
    }

    print(sum, n);
    while (q--) {
        int pos;
        cin >> pos;
        ll x;
        cin >> x;
        sum -= a[pos];
        a[pos] = x;
        sum += x;
        print(sum, n);
    }

}