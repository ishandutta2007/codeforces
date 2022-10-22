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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        if (k >= n) {
            ll result = 0;
            for (ll i = k - 1; i >= k - n; i--) {
                result += i;
            }

            for (int i = 0; i < n; i++) {
                result += a[i];
            }

            cout << result << "\n";
        } else {
            ll result = (k - 1) * k / 2;
            ll max_k_sum = 0;
            for (int i = 0; i < k; i++) {
                max_k_sum += a[i];
            }

            ll running_k_sum = max_k_sum;
            for (int i = k; i < n; i++) {
                running_k_sum += a[i] - a[i - k];
                max_k_sum = max(max_k_sum, running_k_sum);
            }

            cout << result + max_k_sum << "\n";
        }
    }
}