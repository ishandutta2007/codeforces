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
using namespace std;
typedef long long ll;

ll one_digit(ll x) {
    int hack = 0;
    int digit = -1;
    while (x > 0) {
        int d = x % 10;
        if (d > 1) {
            if (digit != -1 && d != digit) {
                return -1;
            } else {
                digit = d;
            }
        }

        x /= 10;
    }

    return digit;
}

bool no_more(ll x) {
    while (x > 0) {
        if (x % 10 > 1) return false;
        x /= 10;
    }

    return true;
}

int solve(ll x, ll power, unordered_map<ll, int>& computed) {
    if (computed.find(x) != computed.end()) return computed[x];

    if (x >= power) return 0;

    vector<bool> is_digit(10, false);
    ll x_c = x;
    while (x_c > 0) {
        int d = x_c % 10;
        x_c /= 10;

        is_digit[d] = true;
    }

    int result = 10000;

    for (ll d = 2; d < 10; d++) {
        if (!is_digit[d]) continue;

        result = min(result, 1 + solve(x * d, power, computed));
    }

    computed[x] = result;

    return result;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n; ll x;
    cin >> n >> x;
    
    ll power = 1;
    for (int i = 1; i <= n - 1; i++) power = power * (ll) 10;

    unordered_map<ll, int> computed;

    if (solve(x, power, computed) > 1000) {
        cout << "-1\n";
    } else {
        cout << solve(x, power, computed) << "\n";
    }
}