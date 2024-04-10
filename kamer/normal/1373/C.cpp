#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.length();
        vector<int> counts(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            if (s[i - 1] == '+') counts[i] = counts[i - 1] + 1;
            else counts[i] = counts[i - 1] - 1;
        }
        ll res = 0;
        ll counter = 0;
        for (ll i = 1; i <= n; i++) {
            while (counter + counts[i] < 0) {
                res += i;
                counter++;
            }
        }
        res += n;
        cout << res << "\n";
    }
}