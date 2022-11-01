#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 1000005

using namespace std;

int v[N];
int n;

vector<int> pf(int x) {
    vector<int> r;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) {
            r.push_back(i);
            while (x%i == 0) x /= i;
        }
    }
    if (x > 1) r.push_back(x);
    return r;
}

typedef long long ll;

bool del[N];
bool add[N];
long long c[N], d[N];
ll a, b;

long long calc(int g) {
    FO(i,0,n) {
        add[i] = del[i] = false;

        int r = v[i] % g;
        if (r == g-1 || r == 1) add[i] = true;
        else if (r != 0) del[i] = true;
    }
    c[0] = 0;
    FO(i,0,n) {
        ll cst = (add[i] ? b : del[i] ? ll(1e17) : 0) - a;
        c[i+1] = cst+c[i];
        c[i+1] = min(c[i+1], ll(1e17));
    }
    d[0] = 0;
    FO(i,0,n) {
        ll cst = (add[n-i-1] ? b : del[n-i-1] ? ll(1e17) : 0) - a;
        d[i+1] = cst+d[i];
        d[i+1] = min(d[i+1], ll(1e17));
    }
    ll res = 1e17;
    // i == 0
    FO(j,1,n+1) res = min(res, n*a + c[0] + d[j]);
    ll md = 1e17;
    for (int i = n; i >= 1; i--) {
        md = min(md, d[n-i]);
        res = min(res, n*a + c[i] + md);
    }
    return res;
}

int main() {
    scanf("%d%lld%lld", &n, &a, &b);
    FO(i,0,n) scanf("%d", v+i);
    ll ans = 1e17;
    for (int t = v[0]-1; t <= v[0]+1; t++) {
        vector<int> p = pf(t);
        for (int x : p) ans = min(ans,calc(x));
    }
    for (int t = v[n-1]-1; t <= v[n-1]+1; t++) {
        vector<int> p = pf(t);
        for (int x : p) ans = min(ans,calc(x));
    }
    printf("%lld\n", ans);
}