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

const ld inf = 1e10;
const int ops = 500;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ld start;
    cin >> start;

    vector<ld> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ld lf = 0, rg = inf;

    for (int op = 0; op < ops; ++op) {
        ld m = (lf + rg) / 2;
        bool ok = true;
        if ((m + start) / a[0] > m) {
            ok = false;
        } else {
            m -= (m + start) / a[0];
        }
        if (ok) {
            for (int i = 1; i < n; ++i) {
                if ((m + start) / b[i] > m) {
                    ok = false;
                    break;
                } else {
                    m -= (m + start) / b[i];
                }
                if ((m + start) / a[i] > m) {
                    ok = false;
                    break;
                } else {
                    m -= (m + start) / a[i];
                }
            }
        }
        if (ok) {
            if ((m + start) / b[0] > m) {
                ok = false;
            } else {
                m -= (m + start) / b[0];
            }
        }
        if (ok) {
            rg = (rg + lf) / 2;
        } else {
            lf = (lf + rg) / 2;
        }
    }

    if (lf > (2e9)) {
        cout << "-1\n";
    } else {
        cout << fixed;
        cout.precision(10);
        cout << lf << "\n";
    }

}