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
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> diff(n, 0);
    for (int i = 1; i < n - 1; i++) diff[i] = a[i + 1] - a[i - 1] - 2;
    vector<ll> sums(n, 0);
    for (int i = 1; i < n - 1; i++) sums[i] = sums[i - 1] + diff[i];

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            cout << k - 1 << "\n";
            continue;
        }
        ll initCount = sums[r - 1] - sums[l];
        initCount += a[l + 1] - 2;
        initCount += (k - a[r - 1] - 1);
        cout << initCount << "\n";
    }
}