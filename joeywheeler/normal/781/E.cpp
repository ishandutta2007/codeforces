#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

set<int> rt[200005];

int h, w, n;

void up(int l, int r, int x) {
    l += w; r += w;
    for (; l < r; l /= 2, r /= 2) {
        if (l&1) {
            if (x>0) rt[l++].insert(x);
            else rt[l++].erase(-x);
        }
        if (r&1) {
            if (x>0) rt[--r].insert(x);
            else rt[--r].erase(-x);
        }
    }
}

int q(int i) {
    i += w;
    int ans = 0;
    for (; i > 0; i /= 2) {
        if (sz(rt[i])) ans = max(ans, *rt[i].rbegin());
    }
    return ans;
}

int u[200005], l[200005], r[200005], s[200005];
int bi[200005];

multiset<pair<int,int> > tr;
map<int,int> dp;

bool cmp(int i, int j) {
    return u[i] < u[j];
}

int qdp(int x) {
    int y = q(x);
    return dp[y];
}

void uh(int h) {
    while (sz(tr) && tr.begin()->first < h) {
        int i = tr.begin()->second;
        up(l[i], r[i], -u[i]);
        tr.erase(tr.begin());
    }
}

int main() {
    scanf("%d %d %d", &h, &w, &n);
    FO(i,0,n) {
        scanf("%d %d %d %d", u+i, l+i, r+i, s+i);
        l[i]--;
        bi[i] = i;
    }
    sort(bi,bi+n,cmp);
    dp[0] = 1;
    FO(_i,0,n) {
        int i = bi[_i];
        uh(u[i]);

        int res = 0;
        if (l[i] == 0) res += qdp(r[i]);
        else res += qdp(l[i]-1);
        if (r[i] == w) res += qdp(l[i]-1);
        else res += qdp(r[i]);
        if (res >= MOD) res -= MOD;

        dp[u[i]] = res;
        tr.emplace(u[i]+s[i], i);

        up(l[i], r[i], u[i]);
    }
    uh(h+1);

    long long ans = 0;
    FO(i,0,w) ans += qdp(i);
    printf("%lld\n", ans % MOD);
}