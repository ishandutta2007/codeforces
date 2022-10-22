#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <utility>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        ll prevMax = a[0];
        int maxCount = 0;
        for (int i = 1; i < n; i++) {
            int currCount = 0;
            ll appendant = 0;
            while (prevMax > a[i] + appendant) {
                currCount++;
                appendant = appendant * ((ll) 2) + ((ll) 1);
            }
            maxCount = max(maxCount, currCount);
            prevMax = max(prevMax, a[i]);
        }
        cout << maxCount << "\n";
    }
}