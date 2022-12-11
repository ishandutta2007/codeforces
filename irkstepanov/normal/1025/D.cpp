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

const int nmax = 710;

int a[nmax];
bool ok[nmax][nmax];
bool pref[nmax][nmax];
bool suff[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            cout << "No\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (__gcd(a[i], a[j]) > 1) {
                ok[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        pref[i][i] = true;
        suff[i][i] = true;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = i + 1; k <= j; ++k) {
                if (ok[i][k] && suff[i + 1][k] && pref[k][j]) {
                    pref[i][j] = true;
                    break;
                }
            }
            for (int k = i; k < j; ++k) {
                if (ok[k][j] && suff[i][k] && pref[k][j - 1]) {
                    suff[i][j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (suff[0][i] && pref[i][n - 1]) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

}