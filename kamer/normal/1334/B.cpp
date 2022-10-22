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
    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll count = n - 1;
        ll sum = 0;
        while (count >= 0) {
            sum += a[count];
            if (sum < (n - count) * x) {
                break;
            }
            count--;
        }
        cout << n - 1 - count << "\n";
    }
}