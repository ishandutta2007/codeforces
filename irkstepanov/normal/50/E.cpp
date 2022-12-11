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
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int nmax = 6e6;

bool used[2 * nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll maxb, maxc;
    cin >> maxb >> maxc;
    ll ans = 0;

    for (ll b = 1; b * b <= maxc && b <= maxb; ++b) {
        //ll c = b * b;
        used[-b + nmax] = true;
        ++ans;
    }

    for (ll b = 2; b <= maxb; ++b) {
        ll rg = min(maxc, b * b - 1);
        ans += rg * 2;
    }

    for (ll b = 2; b <= maxb; ++b) {
        for (ll a = b - 1; a >= 1 && b * b - a * a <= maxc; --a) {
            ll r = -b - a;
            if (used[r + nmax]) {
                --ans;
            } else {
                used[r + nmax] = true;
            }
            r = -b + a;
            if (used[r + nmax]) {
                --ans;
            } else {
                used[r + nmax] = true;
            }
        }
    }

    cout << ans << "\n";

}