#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
void add(LL& x, LL y) {
    if ((x += y) >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    vector<LL> f(64);
    //a b c >a >b >c
    f[0] = 1;
    for (char sc : s) {
        vector<LL> g(64);
        for (int i = 0; i < 64; i += 1) {
            int a = i & 1, b = (i >> 1) & 1, c = (i >> 2) & 1;
            int ga = (i >> 3) & 1, gb = (i >> 4) & 1, gc = (i >> 5) & 1;
            for (int ca = 0; ca < 2; ca += 1) if (a or ca <= sc - '0')
            for (int cb = 0; cb < 2; cb += 1) if (b or cb <= sc - '0')
            for (int cc = 0; cc < 2; cc += 1) if (c or cc <= sc - '0') {
                int na = a or ca < sc - '0';
                int nb = b or cb < sc - '0';
                int nc = c or cc < sc - '0';
                int nga = ga, ngb = gb, ngc = gc;
                int nabc = ca + cb * 2 + cc * 4;
                if (nabc == 1) nga = 1;
                if (nabc == 2) ngb = 1;
                if (nabc == 4) ngc = 1;
                if (nabc == 6) nga = 1;
                if (nabc == 5) ngb = 1;
                if (nabc == 3) ngc = 1;
                int ni = na + nb * 2 + nc * 4 + nga * 8 + ngb * 16 + ngc * 32;
                add(g[ni], f[i]);
            }
        }
        f.swap(g);
    }
    LL ans = 0;
    for (int i = 0; i < 8; i += 1)
        add(ans, f[i + 56]);
    cout << ans;
    return 0;
}