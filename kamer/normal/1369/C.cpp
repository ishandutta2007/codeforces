#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> w(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> w[i];
        sort(a.begin(), a.end());
        sort(w.begin(), w.end());
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += a[n - 1 - i];
            w[i]--;
            if (w[i] == 0) {
                sum += a[n - 1 - i];
            }
        }
        int currIndex = n - k;
        for (int i = 0; i < k; i++) {
            if (w[i] > 0) {
                currIndex = currIndex - w[i];
                sum += a[currIndex];
            }
        }
        cout << sum << "\n";
    }
}