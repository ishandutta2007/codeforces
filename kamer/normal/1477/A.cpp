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
    if (b == 0) return a;
    if (a == b) return a;
    return gcd(b, a % b);
}

tuple<ll, ll> find_prog(ll a, ll b) {
    ll d = max(b - a, a - b);
    if (d == 0) return { a, 0 };
    a = a % d;
    if (a < 0) a += d;
    return { a, d };
}

// 0 <= a < d OR d = 0
tuple<ll, ll> find_prog(ll a, ll d, ll b) {
    if (d == 0) return find_prog(a, b);
    
    b = b % d;
    if (b < 0) b += d;
    ll s = max(b - a, a - b);
    s = gcd(s, d);
    return { a % s, s };

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        auto [l, r] = find_prog(a[0], a[1]);
        for (int i = 2; i < n; i++) {
            auto [l0, r0] = find_prog(l, r, a[i]);
            l = l0, r = r0;
        }
        
        if (r == 0) {
            if (l == k) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            k = k % r;
            if (k < 0) k += r;
            if (k == l) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    }
}