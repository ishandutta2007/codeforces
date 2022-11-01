#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, q;

int a[200005];
int p[500005], V[500005];
int c[500005];
bool o[200005];
ll res = 0;

int main() {
    scanf("%d%d", &n, &q);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,2,500005) if (!p[i]) for (int j = i; j < 500005; j += i) if (!p[j]) {
        p[j] = i;
    }
    V[1] = 1;
    FO(i,2,500005) if (p[i] == p[i/p[i]]) V[i] = V[i/p[i]];
    else V[i] = p[i] * V[i/p[i]];
    FO(i,0,n) a[i] = V[a[i]];
    FO(i,0,q) {
        int x; scanf("%d", &x); x--;
        int s = o[x] ? -1 : 1;
        o[x] = !o[x]; x = a[x];
        vector<int> v;
        for (int y = x; y != 1; y /= p[y]) v.push_back(p[y]);
        FO(m,0,1<<sz(v)) {
            int l = 1;
            if (__builtin_popcount(m)&1) l *= -1;

            int y = 1;
            FO(j,0,sz(v)) if (m&(1<<j)) y *= v[j];

            res -= l * c[y] * 1ll * (c[y]-1) / 2;
            c[y] += s;
            res += l * c[y] * 1ll * (c[y]-1) / 2;
        }
        printf("%lld\n", res);
    }
}