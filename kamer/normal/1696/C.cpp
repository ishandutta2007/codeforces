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

vector<tuple<ll, ll>> decomp(const vector<int>& a, ll m) {
    int n = a.size();

    vector<tuple<ll, ll>> a_d;
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        ll occ = 1;
        while (x % m == 0) {
            x /= m;
            occ *= m;
        }

        if (a_d.size() > 0 && get<0>(a_d[a_d.size() - 1]) == x) {
            a_d[a_d.size() - 1] = { x, get<1>(a_d[a_d.size() - 1]) + occ };
        } else {
            a_d.emplace_back(x, occ);
        }
    }

    return a_d;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int k;
        cin >> k;
        vector<int> b(k);
        for (int i = 0; i < k; i++) cin >> b[i];

        if (decomp(a, m) == decomp(b, m)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}