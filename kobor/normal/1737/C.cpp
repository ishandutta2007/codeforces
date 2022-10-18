#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: a)
#define PB push_back
#define SZ(x) ((int)x.size())
#define X first
#define Y second
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
constexpr int INF = 0x3f3f3f3f;

int n;

int gt(int a, int b) {
    return a % 2 * 2 + b % 2;
}

bool corn(int a, int b) {
    return (a == 1 || a == n) && (b == 1 || b == n);
}

void solve() {
    cin >> n;
    vi kot(4);
    vector<ii> inp;
    int x, y, rx = -1, ry = -1;
    FOR(i, 0, 4) {
        cin >> x >> y;
        if(i != 3) inp.PB({x, y});
        if(i != 3 && corn(x, y)) rx = x, ry = y;
        kot[gt(x, y)] += (i == 3 ? -1 : 1);
    }
    if(rx != -1) {
        bool ok = 0;
        TRAV(p, inp) if(abs(p.X - rx) + abs(p.Y - ry) > 1) ok = 1;
        if(!ok) {
            cout << (rx == x || ry == y ? "YES\n" : "NO\n");
            return;
        }
    }
    cout << (*min_element(kot.begin(), kot.end()) == -1 ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    FOR(te, 0, tt) solve();
    // solve();
    return 0;
}