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

const ll MOD = 998244353;

ll expo(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ll root = expo(a, n / 2);
    root = (root * root) % MOD;
    if (n % 2 == 1) return (root * a) % MOD;
    else return root;
}

ll inv(ll a) {
    return expo(a, MOD - 2);
}

ll mod(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; i++) {
        res = (res * (n - i + 1)) % MOD;
        res = (res * inv(i)) % MOD;
    }

    return res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> pos(n + 1, -1);
    for (int i = 0; i < n; i++) pos[s[i]] = i;

    int countEqual = 0;
    for (int i = 0; i < n - 1; i++) {
        if (pos[s[i] + 1] < pos[s[i + 1] + 1]) countEqual++;
    }

    k += countEqual;
    if (k < n) {
        cout << "0\n";
        return 0;
    }

    cout << mod(k, n) << "\n";
}