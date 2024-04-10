#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int mn[400005], mx[400005];
int a[200005];
vector<int> p[1000005];

int mnq(int l, int r) {
    int ans = 1e9;
    for (l += n, r += n; l < r; l/=2, r/=2) {
        if (l&1) ans = min(ans, mn[l++]);
        if (r&1) ans = min(ans, mn[--r]);
    }
    return ans;
}

int mxq(int l, int r) {
    int ans = -1;
    for (l += n, r += n; l < r; l/=2, r/=2) {
        if (l&1) ans = max(ans, mx[l++]);
        if (r&1) ans = max(ans, mx[--r]);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) {
        scanf("%d", a+i);
        p[a[i]].push_back(i);
    }

    FO(i,0,n) mn[n+i] = a[i];
    for (int i = n-1; i > 0; i--) mn[i] = min(mn[2*i],mn[2*i+1]);

    FO(i,0,n) mx[n+i] = a[i];
    for (int i = n-1; i > 0; i--) mx[i] = max(mx[2*i],mx[2*i+1]);

    FO(i,0,m) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x); l--;
        int mnv = mnq(l,r);
        int mxv = mxq(l,r);
        int bv = -1;
        if (mnv != x) bv = mnv;
        if (mxv != x) bv = mxv;
        if (bv == -1) printf("-1\n");
        else printf("%d\n", 1+*lower_bound(p[bv].begin(),p[bv].end(),l));
    }
}