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

const ll MOD = 1000000007;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<int> counts(30, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int pow_2 = 0;
        while (a % 2 == 0) {
            pow_2++;
            a /= 2;
        }
        counts[pow_2]++;
    }

    vector<ll> powers(n + 1, 1);
    for (int i = 1; i < n + 1; i++) {
        powers[i] = (powers[i - 1] * (ll) 2) % MOD;
    }

    ll res = 0;
    for (int i = 0; i < 30; i++) {
        n -= counts[i];
        if (i == 0) {
            res = (res + (powers[counts[i]] - 1) * powers[n]) % MOD;
        } else if (counts[i] > 0) {
            res = (res + (powers[counts[i] - 1] - 1) * powers[n]) % MOD;
        }
    }

    cout << res << "\n";


}