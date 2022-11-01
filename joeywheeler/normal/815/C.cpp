#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define vv vector

using namespace std;

typedef long long ll;

int n, b;
int x[5005];
vector<int> u[5005];
int c[5005], d[5005];

vv<vv<ll>> go(int i) {
    vv<vv<ll>> l(2, vv<ll>(2));
    l[0][1] = c[i];
    l[1][0] = 1ll<<60;
    l[1][1] = c[i]-d[i];
    for (int j : u[i]) {
        auto r = go(j);
        vv<vv<ll>> s(2, vv<ll>(sz(l[0])+sz(r[0])+1, 1ll<<60));
        fo(k,0,2) {
            fo(y,0,sz(l[0])) fo(z,0,sz(r[0])) {
                s[k][y+z] = min(s[k][y+z],
                        l[k][y] + r[k][z]
                        );
                if (k) {
                    s[k][y+z] = min(s[k][y+z],
                            l[k][y] + r[0][z]
                            );
                }
            }

        }
        l = s;
    }
    return l;
}

int main() {
    scanf("%d %d", &n, &b);
    fo(i,0,n) {
        scanf("%d %d", c+i, d+i);
        if (i != 0) {
            scanf("%d", x+i);
            x[i]--;
            u[x[i]].push_back(i);
        }
    }
    auto l = go(0);
    for (int i = n; i >= 0; i--) {
        if (min(l[0][i],l[1][i]) <= b) {
            printf("%d\n", i);
            return 0;
        }
    }
}