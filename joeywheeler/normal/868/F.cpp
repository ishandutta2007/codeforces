#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[100005];
int cnt[100005];
ll cst;
int ci, cj;

void adde(int i) {
    cst += cnt[a[i]];
    cnt[a[i]]++;
}

void reme(int i) {
    cnt[a[i]]--;
    cst -= cnt[a[i]];
}

void mvrng(int ni, int nj) {
    while (ci < ni) reme(ci++);
    while (ci > ni) adde(--ci);
    while (cj < nj) adde(cj++);
    while (cj > nj) reme(--cj);
}

ll dp[100005];
ll ndp[100005];
int n, k;

void initdp() {
    fo(j,0,n) adde(j);
    fo(i,0,n+1) {
        dp[i] = cst;
        if (i != n) reme(i);
    }
}

void cdp(int si, int ei, int rsj, int rej) {
    if (si == ei) return;

    int i = (si+ei)/2;

    int bj = max(rsj,i);
    mvrng(i, bj);
    ll bv = cst + dp[bj];
    fo(j,bj,rej+1) {
        mvrng(i, j);
        ll vl = cst + dp[j];
        if (vl <= bv) {
            bj = j;
            bv = vl;
        }
    }

    ndp[i] = bv;
    cdp(si, i, rsj, bj);
    cdp(i+1, ei, bj, rej);
}

int main() {
    scanf("%d %d", &n, &k);
    fo(i,0,n) scanf("%d", a+i);
    initdp();
    //fo(i,0,n+1) printf("%lld ", dp[i]);
    //printf("\n~~\n");
    fo(_,0,k-1) {
        cdp(0,n+1,0,n+1);
        fo(i,0,n+1) dp[i] = ndp[i];
        //fo(i,0,n+1) printf("%lld ", dp[i]);
        //printf("\n~~\n");
    }
    printf("%lld\n", dp[0]);
}