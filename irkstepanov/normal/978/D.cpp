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

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (n <= 2) {
        cout << "0\n";
        return 0;
    }

    int ans = n + 10;

    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            ll a1 = b[0] + x;
            ll a2 = b[1] + y;
            ll d = a2 - a1;
            int curr = 0;
            if (x) {
                ++curr;
            }
            if (y) {
                ++curr;
            }
            ll pr = a2;
            bool ok = true;
            for (int i = 2; i < n; ++i) {

                ll val = pr + d;
                if (b[i] == val - 1) {
                    ++curr;
                } else if (b[i] == val + 1) {
                    ++curr;
                } else if (b[i] != val) {
                    ok = false;
                    break;
                }
                pr = val;
            }
            if (ok) {
                ans = min(ans, curr);
            }
        }
    }

    if (ans > n) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

}