#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;

mt19937 rnd(58);


void solve() {
    long double px, py, vx, vy, a, b, c, d, nvx, nvy;
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    long double r = sqrt(vx * vx + vy * vy);
    vx /= r;
    vy /= r;
    nvx = -vy;
    nvy = vx;
    cout << fixed << setprecision(12);
    cout << px + vx * b << ' ' << py + vy * b << endl;
    cout << px + nvx * a / 2 << ' ' << py + nvy * a / 2 << endl;
    cout << px + nvx * c / 2 << ' ' << py + nvy * c / 2 << endl;
    cout << px + nvx * c / 2 - vx * d << ' ' << py + nvy * c / 2 - vy * d << endl;
    cout << px - nvx * c / 2 - vx * d << ' ' << py - nvy * c / 2 - vy * d << endl;
    cout << px - nvx * c / 2 << ' ' << py - nvy * c / 2 << endl;
    cout << px - nvx * a / 2 << ' ' << py - nvy * a / 2 << endl;

}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}