#include <bits/stdc++.h>

#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 998244353

#define T 330

using namespace std;

typedef long long ll;

int n, k;
int a[100005];
int ls[100005];
int pls[100005];
int dp[200005];

int lv[T];
int v[T][T];
int sm[T][T];

void mad(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void cmpsm(int i) {
    fo(j,0,T) sm[i][j] = 0;
    fo(j,0,T) mad(sm[i][v[i][j]], dp[i*T+j]);
    fo(j,1,T) mad(sm[i][j], sm[i][j-1]);
}

void add(int l, int r, int s) {
    fo(i,0,T) {
        int x = max(l,i*T), y = min(r,(i+1)*T);
        if (x == i*T && y == (i+1)*T) {
            lv[i] += s;
        } else if (x < y) {
            fo(j,0,T) v[i][j] += lv[i];
            lv[i] = 0;
            fo(j,x-i*T,y-i*T) v[i][j] += s;
            lv[i] = 1e9;
            fo(j,0,T) lv[i] = min(lv[i], v[i][j]);
            fo(j,0,T) v[i][j] -= lv[i];
            cmpsm(i);
        }
    }
}

int qsm() {
    ll r = 0;
    fo(i,0,T) {
        int tk = min(T-1, k - lv[i]);
        if (0 <= tk) r += sm[i][tk];
    }
    return r % MOD;
}

void sdp(int p, int x) {
    dp[p] = x;
    cmpsm(p/T);
}

int main() {
    scanf("%d %d", &n, &k);
    fo(i,0,n) scanf("%d", a+i);
    sdp(0, 1);
    fo(i,0,n) {
        add(pls[a[i]],ls[a[i]],-1);
        pls[a[i]] = ls[a[i]]; ls[a[i]] = i+1;
        add(pls[a[i]],ls[a[i]],1);
        int r = qsm();
        if (i == n-1) printf("%d\n", r);
        else sdp(i+1, r);
    }
}