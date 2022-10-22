#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll curr_max = -1000000000;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (ll i = max(n - 200, (ll) 0); i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                curr_max = max(curr_max, (i + 1) * (j + 1) - k * (a[i] | a[j]));
            }
        }

        cout << curr_max << "\n";
    }
}