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
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        ll sum_a = 0;
        vector<ll> diffs(n);
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            sum_a += a;

            diffs[i] = n - 1 - i - a;
        }

        sort(diffs.begin(), diffs.end());
        
        ll optimal_sum = sum_a;
        ll running_diffs = 0;
        for (ll i = 1; i <= k; i++) {
            running_diffs += diffs[i - 1];
            optimal_sum = min(optimal_sum, sum_a + running_diffs - i * (i - 1) / 2);
        }

        cout << optimal_sum << "\n";
    }
}