#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
typedef int ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        unordered_map<ll, ll> counts;
        counts.reserve(1024);
        counts.max_load_factor(0.25);
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            if (a % k != 0) {
                counts[k - a % k]++;
            }
        }



        ll maxim = -1;
        ll maxIndex = -1;
        for (auto count : counts) {
            if (maxim <= count.second) {
                if (maxim < count.second || maxIndex < count.first) maxIndex = count.first;
                maxim = count.second;
            }
        }

        if (maxim <= 0) {
            cout << "0\n";
        } else {
            cout << ((long long) (maxim - 1)) * k + maxIndex + 1 << "\n";
        }
        
    }
}