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
        ll s, n, k;
        cin >> s >> n >> k;
        if (s == k) {
            cout << "YES\n";
            continue;
        }

        ll m = (((s / k) + 2) / 2) * (s % k + 1) + (((s / k) + 1) / 2) * (k - 1 - s % k);
        if ((n + 1) <= m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}