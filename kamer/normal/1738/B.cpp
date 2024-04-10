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
#include <complex>
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
        vector<ll> s(k);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }
        if (k == 1) {
            cout << "YES\n";
            continue;
        }

        bool increasing = true;
        for (int i = 0; i < k - 2; i++) {
            if (s[i + 1] - s[i] > s[i + 2] - s[i + 1]) {
                increasing = false;
                break;
            }
        }

        if (!increasing) {
            cout << "NO\n";
            continue;
        }

        if (s[0] > (s[1] - s[0]) * (n - k + 1)) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}