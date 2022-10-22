#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    ll n, m;
    cin >> n >> m;
    n += 2; m += 2;
    ll x, k, y;
    cin >> x >> k >> y;
    vector<ll> a(n, 0);
    vector<ll> b(m, 0);
    for (ll i = 0; i < n - 2; i++) cin >> a[i + 1];
    for (ll i = 0; i < m - 2; i++) cin >> b[i + 1];
    vector<ll> aIndex(m, 0);
    ll bToFind = 1;
    for (ll i = 1; i < n; i++) {
        if (a[i] == b[bToFind]) {
            aIndex[bToFind] = i;
            bToFind++;
        }
    }

    if (aIndex[m - 1] != n - 1) {
        cout << "-1\n";
        return 0;
    }

    ll manaCost = 0;
    for (ll i = 0; i < m - 1; i++) {
        ll maxB = max(b[i], b[i + 1]);
        bool biggerB = false;
        bool smallerB = false;
        for (ll j = aIndex[i] + 1; j <= aIndex[i + 1] - 1; j++) {
            if (a[j] > maxB) biggerB = true;
            if (a[j] < maxB) smallerB = true;
        }

        ll numNumbers = aIndex[i + 1] - aIndex[i] - 1;

        if (biggerB && (numNumbers < k)) {
            cout << "-1\n";
            return 0;
        }
        
        if ((!smallerB) && (numNumbers < k) && (numNumbers > 0)) {
            cout << "-1\n";
            return 0;
        }

        if (y * k <= x) {
            if (biggerB) {
                manaCost = manaCost + x + y * (numNumbers - k);
            } else {
                manaCost = manaCost + y * numNumbers;
            }
        } else {
            manaCost = manaCost + x * (numNumbers / k) + y * (numNumbers % k); 
        }
    }

    cout << manaCost << "\n";

}