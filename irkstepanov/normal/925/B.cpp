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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll x[2];
    cin >> x[0] >> x[1];

    vector<pll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(all(a));

    int best[2] = {-1, -1};
    for (int i = n - 1; i >= 0; --i) {
        if (a[i].first * (n - i) >= x[0] && best[0] == -1) {
            best[0] = i;
        }
        if (a[i].first * (n - i) >= x[1] && best[1] == -1) {
            best[1] = i;
        }
    }

    for (int t = 0; t < 2; ++t) {
        for (int k = 1; k < n; ++k) {
            if (a.back().first * k < x[t]) {
                continue;
            }
            int lf = -1, rg = n - 1;
            while (rg - lf > 1) {
                int md = (lf + rg) >> 1;
                if (a[md].first * k < x[t]) {
                    lf = md;
                } else {
                    rg = md;
                }
            }
            lf = rg;
            if (lf + k >= n) {
                continue;
            }
            if (best[1 ^ t] < lf + k) {
                continue;
            }
            cout << "Yes\n";
            if (t == 0) {
                cout << k << " " << n - best[1 ^ t] << "\n";
                for (int i = lf; i < lf + k; ++i) {
                    cout << a[i].second << " ";
                }
                cout << "\n";
                for (int i = best[1 ^ t]; i < n; ++i) {
                    cout << a[i].second << " ";
                }
                cout << "\n";
                return 0;
            } else {
                cout << n - best[1 ^ t] << " " << k << "\n";
                for (int i = best[1 ^ t]; i < n; ++i) {
                    cout << a[i].second << " ";
                }
                cout << "\n";
                for (int i = lf; i < lf + k; ++i) {
                    cout << a[i].second << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "No\n";

}