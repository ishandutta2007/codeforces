#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int SUP = 100006;

int main(void) {
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> powers(SUP, 1);
    vector<ll> sums(SUP, 0);
    vector<ll> comb(SUP, 0);

    for (int i = 1; i < SUP; i++) {
        powers[i] = (powers[i - 1] * 10) % MOD;
    }

    for (int i = 1; i < SUP; i++) {
        sums[i] = (sums[i - 1] + powers[i - 1] * i) % MOD;
    }

    for (ll i = 0; i < SUP; i++) {
        comb[i] = (i * (i + 1) / 2) % MOD;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        res = (res + c * ((powers[n - 1 - i] * comb[i]) % MOD) + c * sums[n - 1 - i]) % MOD;
    }

    cout << res << "\n";
}