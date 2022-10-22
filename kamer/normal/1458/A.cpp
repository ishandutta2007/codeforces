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

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (a == b) return a;
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    vector<ll> uniqueA;
    ll prev = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != prev) {
            uniqueA.push_back(a[i]);
            prev = a[i];
        }
    }

    int l = uniqueA.size();
    if (l == 1) {
        for (int i = 0; i < m; i++) {
            cout << uniqueA[0] + b[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    ll allGCD = uniqueA[1] - uniqueA[0];
    for (int i = 1; i < l - 1; i++) {
        allGCD = gcd(allGCD, uniqueA[i + 1] - uniqueA[i]);
    }

    for (int i = 0; i < m; i++) {
        cout << gcd(allGCD, uniqueA[0] + b[i]) << " ";
    }
    cout << "\n";
    return 0;
}