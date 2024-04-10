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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll d;
    cin >> d;

    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    set<ll> ans;
    for (int i = 0; i < n; ++i) {
        for (int sgn = -1; sgn <= 1; sgn += 2) {
            ll val = x[i] + d * sgn;
            ll z = d;
            for (int j = 0; j < n; ++j) {
                z = min(z, abs(x[j] - val));
            }
            if (z == d) {
                ans.insert(val);
            }
        }
    }

    cout << sz(ans) << "\n";

}