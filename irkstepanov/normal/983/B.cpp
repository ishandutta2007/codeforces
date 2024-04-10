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

const int nmax = 5050;

int ans[nmax][nmax];
int a[nmax];

int res[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        ans[i][1] = a[i];
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i + k - 1 < n; ++i) {
            int mask = k - 1;
            int val = a[i];
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                val ^= a[i + submask];
            }
            ans[i][k] = max(ans[i][k - 1], val);
        }
    }

    for (int i = 0; i < n; ++i) {
        res[i][1] = ans[i][1];
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i + k - 1 < n; ++i) {
            res[i][k] = max(ans[i][k], res[i + 1][k - 1]);
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << res[l][r - l + 1] << "\n";
    }

}