#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[1000005];
int nw[1000005];
int n, a, b, t;
typedef long long ll;

int cw(int l, int r) { return nw[r]-nw[l]; }
int ch(int l, int r) { return (r-l) - (nw[r]-nw[l]); }

ll calc(int l, int r) {
    ll sl = (n-l)*a;
    ll sr = (r-1-n)*a;
    ll nv = r-l;
    ll nr = cw(l,r);
    return sl+sr+nv+nr*b + min(sl,sr);
}

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &t);
    scanf(" %s", s);
    FO(i,0,n) s[i+n] = s[i];
    FO(i,0,2*n) {
        nw[i+1] = nw[i] + (s[i] == 'w' ? 1 : 0);
    }
    int ans = 0;
    FO(l,0,n+1) {
        int s = n+1, e = 2*n, b = -1;
        while (s <= e) {
            int md = (s+e)/2;
            if (calc(l, md) <= t) {
                //printf("[%d,%d)\n", l, md);
                b = md;
                s = md+1;
            } else e = md-1;
        }
        ans = max(ans, b-l);
    }
    ans = min(ans,n);
    printf("%d\n", ans);
}