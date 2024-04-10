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
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n == 5) {
            cout << a[0] * a[1] * a[2] * a[3] * a[4] << "\n";
            continue;
        }

        if (a[n - 1] <= 0) {
            cout << a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5] << "\n";
            continue;
        }

        ll maxim = a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5];
        maxim = max(maxim, max(a[n-1]*a[0]*a[1]*a[2]*a[3], a[n-1]*a[n-2]*a[n-3]*a[0]*a[1]));
        cout << maxim << "\n";
    }
}