#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll k, d, t;
    cin >> k >> d >> t;

    ll delta = ((k + d - 1) / d) * d - k;
    ll f = (t * 2) / (k * 2 + delta);

    ld ans = f * (k + delta);

    ld done = ld(f) / (2 * t) * (2 * k + delta);

    if (ld(k) / t + done >= 1) {
        ans += (1 - done) * t;
    } else {
        ans += k;
        done += ld(k) / t;
        ans += (1 - done) * t * 2;
    }

    cout << fixed;
    cout.precision(20);
    cout << ans << "\n";

}