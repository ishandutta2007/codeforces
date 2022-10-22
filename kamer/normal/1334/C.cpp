#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cin >> b[i];
        }
        vector<ll> rem(n);
        for (int i = 0; i < n; i++) {
            rem[i] = max((ll)0, a[i] - b[(i + n - 1) % n]);
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += rem[i];
        ll minSum = 1000000000000000000;
        for (int i = 0; i < n; i++) {
            minSum = min(minSum, sum - rem[i] + a[i]);
        }
        cout << minSum << "\n";
    }
}