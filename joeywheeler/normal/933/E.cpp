#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll a[300005];
int n;
ll c[300005][6][2];
ll rm[300005][6][2];

void clc(int i, int j) {
    fo(t,0,2) {
        vector<ll> v(a+i, a+j);
        if (t) reverse(v.begin(), v.end());
        c[i][j-i][t] = 0;
        fo(k,0,sz(v)-1) {
            ll r = min(v[k], v[k+1]);
            c[i][j-i][t] += r;
            v[k] -= r;
            v[k+1] -= r;
        }
        c[i][j-i][t] += v.back();
        rm[i][j-i][t] = v.back();
        fo(k,0,sz(v)-1) {
            if (v[k] != 0) {
                c[i][j-i][t] = 1e12;
            }
        }
        //printf("c[%d][%d][%d]=%lld\n", i, j, t, c[i][j-i][t]);
    }
}

ll cdp[300005][2];
int coptl[300005][2];
int coptl2[300005][2];
int coptb[300005][2];

ll dp(int i, bool p0) {
    if (i == n) return 0;
    if (i == n-1 && p0) return 0;
    if (cdp[i][p0] != -1) return cdp[i][p0];

    ll &res = cdp[i][p0] = 1e18;
    fo(l,1,6) {
        if (i + l < n) {
            ll cc = c[i][l][0];
            ll rr = rm[i][l][0];
            if (rr <= a[i+l]) {
                ll nres = cc + dp(i + l + 1, a[i+l]-rr == 0);
                if (nres < res) {
                    res = nres;
                    coptb[i][p0] = 1;
                    coptl[i][p0] = l;
                }
            }
            fo(l2,1,6) {
                if (i + l + 1 + l2 <= n) {
                    ll cc2 = c[i+l+1][l2][1];
                    ll rr2 = rm[i+l+1][l2][1];
                    if (rr + rr2 <= a[i+l]) {
                        ll nres = cc + cc2 + dp(i + l + l2 + 1, true);
                        if (nres < res) {
                            res = nres;
                            coptb[i][p0] = 2;
                            coptl[i][p0] = l;
                            coptl2[i][p0] = l2;
                        }
                    }
                }
            }
        }
    }
    if (p0) {
        ll nres = dp(i+1, a[i] == 0);
        if (nres < res) {
            res = nres;
            coptb[i][p0] = 3;
        }
        fo(l,1,6) {
            if (i + 1 + l <= n) {
                ll cc = c[i+1][l][1];
                ll rr = rm[i+1][l][1];
                if (rr <= a[i]) {
                    ll nres = cc + dp(i + l + 1, true);
                    if (nres < res) {
                        res = nres;
                        coptb[i][p0] = 4;
                        coptl[i][p0] = l;
                    }
                }
            }
        }
    }
    return res;
}

vector<int> ans;

void bt(int i, int p0) {
    if (i == n) return;
    if (i == n-1 && p0) return;

    if (coptb[i][p0] == 1) {
        int l = coptl[i][p0];
        fo(j,i,i+l) {
            if (a[j] > 0 && a[j+1] > 0) {
                int r = min(a[j], a[j+1]);
                a[j] -= r;
                a[j+1] -= r;
                ans.eb(j+1);
            }
        }
        bt(i+l+1,a[i+l] == 0);
    }
    if (coptb[i][p0] == 2) {
        int l = coptl[i][p0];
        fo(j,i,i+l) {
            if (a[j] > 0 && a[j+1] > 0) {
                int r = min(a[j], a[j+1]);
                a[j] -= r;
                a[j+1] -= r;
                ans.eb(j+1);
            }
        }
        int l2 = coptl2[i][p0];
        for (int j = i+l+l2; j > i+l; j--) {
            if (a[j-1] > 0 && a[j] > 0) {
                int r = min(a[j-1], a[j]);
                a[j-1] -= r;
                a[j] -= r;
                ans.eb(j);
            }
        }
        bt(i+l+1+l2, true);
    }
    if (coptb[i][p0] == 3) {
        bt(i+1, a[i] == 0);
    }
    if (coptb[i][p0] == 4) {
        int l = coptl[i][p0];
        for (int j = i+l; j > i; j--) {
            if (a[j-1] > 0 && a[j] > 0) {
                int r = min(a[j-1], a[j]);
                a[j-1] -= r;
                a[j] -= r;
                ans.eb(j);
            }
        }
        bt(i+l+1, true);
    }
}

int main() {
    memset(cdp, -1, sizeof cdp);
    scanf("%d", &n);
    fo(i,0,n) scanf("%lld", a+i);
    fo(i,0,n) {
        fo(l,1,6) {
            if (i + l <= n) {
                clc(i, i+l);
            }
        }
    }
    ll rdp = dp(0, true);
    //printf("%lld\n", rdp);
    bt(0, true);
    
    printf("%d\n", sz(ans));
    for (int x : ans) printf("%d\n", x);
}