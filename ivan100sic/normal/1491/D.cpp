// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool moze(ll x, ll y) {
    if (x > y) return false;
    if (x == y) return true;
    vector<int> vx, vy;
    for (int i=0; i<30; i++) {
        if (x & (1 << i)) vx.push_back(i);
        if (y & (1 << i)) vy.push_back(i);
    }

    if (vx.size() < vy.size()) return false;
    for (int i=0; i<(int)vy.size(); i++) {
        if (vy[i] < vx[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        cout << (moze(x, y) ? "YES\n" : "NO\n");
    }
}