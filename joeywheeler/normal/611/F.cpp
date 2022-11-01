#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

typedef long long ll;

struct rect {
    int lx, ly, ux, uy;
    int nm;

    bool empty() {
        if (ux < lx || uy < ly) return true;
        return false;
    }

    ll area() {
        return (ux-lx+1) * 1ll * (uy-ly+1) % MOD;
    }
};

rect is(rect a, rect b) {
    rect res;
    res.lx = max(a.lx, b.lx);
    res.ly = max(a.ly, b.ly);
    res.ux = min(a.ux, b.ux);
    res.uy = min(a.uy, b.uy);
    return res;
}

int n, h, w;
char s[500005];
int si[500005];
char m[] = "UDLR";
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int Y = 0, X = 0;

int cntx[500005];
int cnty[500005];
rect rem;
vector<rect> v;

ll calc() {
    ll ans = 0;
    // drift r to calc the ns
    for (rect &o : v) {
        int c = 0;
        rect tmp = o;
        tmp.lx += X;
        tmp.ux += X;
        tmp.ly += Y;
        tmp.uy += Y;
        tmp = is(tmp, rem);
        while (!tmp.empty()) {
            c++;
            ans += tmp.area() * (o.nm + c*1ll*n) % MOD;
            ans %= MOD;
            tmp.lx += X;
            tmp.ux += X;
            tmp.ly += Y;
            tmp.uy += Y;
            tmp = is(tmp, rem);
        }
    }
    return ans;
}

void fx() {
    FO(i,0,n) {
        Y += dy[si[i]];
        X += dx[si[i]];
    }
    if (Y > 0) {
        FO(i,0,n) if (si[i] <= 1) si[i] = 1-si[i];
    }
    if (X > 0) {
        FO(i,0,n) if (si[i] >= 2) si[i] = 5-si[i];
    }
    Y = abs(Y);
    X = abs(X);
}

int cl, cu, cr, cd;

int main() {
    scanf("%d %d %d", &n, &h, &w);
    scanf(" %s", s);
    FO(i,0,n) {
        FO(j,0,4) if (s[i] == m[j]) si[i] = j;
    }
    fx();
    FO(i,0,n) s[i] = m[si[i]];
    ll ans = 0;
    X = 0; Y = 0;
    int mnx = 0, mny = 0, mxx = 0, mxy = 0;
    FO(i,0,n) {
        rect r;
        r.nm = -1;
        if (s[i] == 'U') {
            Y--;
            if (Y < mny) {
                r.nm = i+1;
                r.lx = cl;
                r.ux = w-cr-1;
                r.ly = cu;
                r.uy = cu;
                cu++;
                mny = Y;
            }
        }
        if (s[i] == 'D') {
            Y++;
            if (Y > mxy) {
                r.nm = i+1;
                r.lx = cl;
                r.ux = w-cr-1;
                r.ly = h-1-cd;
                r.uy = h-1-cd;
                cd++;
                mxy = Y;
            }
        }
        if (s[i] == 'L') {
            X--;
            if (X < mnx) {
                r.nm = i+1;
                r.ly = cu;
                r.uy = h-cd-1;
                r.lx = cl;
                r.ux = cl;
                cl++;
                mnx = X;
            }
        }
        if (s[i] == 'R') {
            X++;
            if (X > mxx) {
                r.nm = i+1;
                r.ly = cu;
                r.uy = h-cd-1;
                r.lx = w-1-cr;
                r.ux = w-1-cr;
                cr++;
                mxx = X;
            }
        }
        if (r.nm != -1) {
            v.push_back(r);
            ans += r.area() * r.nm;
            ans %= MOD;
            if (cu+cd == h || cl+cr == w) {
                printf("%lld\n", ans);
                return 0;
            }
        }
    }
    Y *= -1;
    X *= -1;
    if (Y == 0 && X == 0) {
        printf("-1\n");
        return 0;
    }
    rem.lx = cl;
    rem.ux = w-1-cr;
    rem.ly = cu;
    rem.uy = h-1-cd;
    ans += calc();
    ans %= MOD;
    printf("%lld\n", ans);
}