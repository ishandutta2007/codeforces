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
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, d;
    cin >> x >> d;

    vector<ll> ans;
    ll val = 1;

    while (x) {
        int k = 1;
        while ((1LL << k) - 1 <= x) {
            ++k;
        }
        --k;
        for (int i = 0; i < k; ++i) {
            ans.pb(val);
        }
        val += d;
        x -= ((1LL << k) - 1);
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}