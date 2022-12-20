#include <bits/stdc++.h>
//#pragma GCC optimize 03
#define fi first
#define se second
#define ll long long
using namespace std;
const long double inf = 1e9;
const long double EPS = 1e-12;
map <long long, int> m;
map <pair<long long, long long>, int > cnt;

int main() {
    int i, j, k, n;
    long long x, vx, vy, a, b, ans = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    for (i = 0; i < n; ++i) {
        cin >> x >> vx >> vy;
        ans += m[a*vx - vy];
        ++m[a * vx - vy];
        ans -= cnt[{vx, vy}];
        ++cnt[{vx, vy}];
    }
    cout << 2 * ans;
}