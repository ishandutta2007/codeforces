#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1005;
const int MOD = 998244353;

llint n, m, sx, kx, sy, ky, sum, cnt, rr, cc;
llint l[MAXN] [MAXN], p[MAXN] [MAXN];
vector < pair <llint, pair <int, int> > > v;

llint add (llint a, llint b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

llint mul (llint a, llint b) {
    return a*b%MOD;
}

llint sub (llint a, llint b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

llint pot (llint x, llint e) {
    if (e == 0) return 1;
    if (e & 1) {
        return mul(pot(x, e-1), x);
    } else {
        llint t = pot(x, e/2);
        return mul(t, t);
    }
}

llint divv (llint a, llint b) {
    return mul(a, pot(b, MOD-2));
}

llint f (llint x, llint y) {
    llint a = add(mul(cnt, mul(x, x)), mul(cnt, mul(y, y)));
    llint b = add(mul(2, mul(x, sx)), mul(2, mul(y, sy)));
    llint c = add(kx, ky);
    return add(a, sub(c, b));
}

int main () {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &l[i] [j]);
            v.push_back(make_pair(l[i] [j], make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        llint val = v[i].first;
        int ind;
        for (ind = i; ind < v.size() && v[ind].first == val; ind++) {
            int x = v[ind].second.first;
            int y = v[ind].second.second;
            if (cnt > 0) p[x] [y] = divv(add(f(x, y), sum), cnt);
        }
        for (ind = i; ind < v.size() && v[ind].first == val; ind++) {
            int x = v[ind].second.first;
            int y = v[ind].second.second;
            cnt++;
            sum = add(sum, p[x] [y]);
            sx = add(sx, x); kx = add(kx, mul(x, x));
            sy = add(sy, y); ky = add(ky, mul(y, y));
        }
        i = ind - 1;
    }
    cin >> rr >> cc;
    cout << p[rr-1] [cc-1];
    return 0;
}