#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int nxt[200000][4], sl[200000], len[200000];
int sz, last;

long long n;
int m;
char t[100005];
int cache[200005][4];

int gs(int i, int j) {
    if (cache[i][j] != -1) return cache[i][j];
    else if (nxt[i][j] == -1) return 1;
    else {
        int &res = cache[i][j] = 1e9;
        FO(k,0,4) if (nxt[i][k] != -1) res = min(res, 1 + gs(nxt[i][k], j));
        return res;
    }
}

typedef long long ll;

void mul(ll a[4][4], ll b[4][4], ll r[4][4]) {
    FO(i,0,4) FO(j,0,4) {
        r[i][j] = 2e18;
        FO(k,0,4) {
            r[i][j] = min(r[i][j], a[i][k]+b[k][j]);
        }
        if (r[i][j] > 2e18) r[i][j] = 2e18;
    }
}

void pow(ll a[4][4], ll k, ll r[4][4]) {
    if (k == 1) {
        FO(i,0,4) FO(j,0,4) r[i][j] = a[i][j];
    } else {
        ll t[4][4];
        pow(a,k/2,t);
        mul(t,t,r);
        if (k&1) {
            FO(i,0,4) FO(j,0,4) t[i][j] = r[i][j];
            mul(t,a,r);
        }
    }
}

int main() {
    memset(nxt,-1,sizeof nxt);
    sl[0] = -1; sz = 1;
    scanf("%lld %s", &n, t);
    m = strlen(t);
    FO(i,0,m) {
        int cur = sz++;
        len[cur] = len[last]+1;
        int p;
        for (p = last; p != -1 && nxt[p][t[i]-'A'] == -1; p = sl[p]) nxt[p][t[i]-'A'] = cur;
        if (p == -1) {
            sl[cur] = 0;
        } else {
            int q = nxt[p][t[i]-'A'];
            if (len[q] == len[p]+1) sl[cur] = q;
            else {
                int nq = sz++;
                FO(j,0,4) nxt[nq][j] = nxt[q][j];
                sl[nq] = sl[q];
                len[nq] = len[p]+1;
                sl[cur] = sl[q] = nq;
                for (; p != -1 && nxt[p][t[i]-'A'] == q; p = sl[p]) nxt[p][t[i]-'A'] = nq;
            }
        }
        last = cur;
    }
    memset(cache,-1,sizeof cache);
    long long o[4][4];
    FO(i,0,4) FO(j,0,4) o[i][j] = gs(nxt[0][i],j);
    ll s = 1, e = 2e18, b = 1;
    while (s <= e) {
        ll md = (s+e)/2;
        ll t[4][4];
        pow(o,md,t);
        ll mn = 2e18;
        FO(i,0,4) FO(j,0,4) mn = min(mn, t[i][j]);
        if (mn < n) {
            b = md+1;
            s = md+1;
        } else if (mn == n) {
            b = md;
            s = md+1;
        } else {
            e = md-1;
        }
    }
    printf("%lld\n", b);
}