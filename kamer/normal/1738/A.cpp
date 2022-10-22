#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> b, c;
        for (int i = 0; i < n; i++) {
            ll b_el;
            cin >> b_el;
            if (a[i] == 0) {
                b.emplace_back(b_el);
            } else {
                c.emplace_back(b_el);
            }
        }

        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        if (b.size() != c.size()) {
            ll sum = 0;
            for (int i = 0; i < min(b.size(), c.size()); i++) {
                sum = sum + 2 * b[i] + 2 * c[i];
            }

            for (int i = min(b.size(), c.size()); i < b.size(); i++) {
                sum += b[i];
            }

            for (int i = min(b.size(), c.size()); i < c.size(); i++) {
                sum += c[i];
            }

            cout << sum << "\n";
        } else {
            ll sum = 0;
            for (int i = 0; i < b.size(); i++) {
                sum = sum + 2 * b[i] + 2 * c[i];
            }

            sum -= min(b[b.size() - 1], c[c.size() - 1]);
            cout << sum << "\n";
        }
    }
}