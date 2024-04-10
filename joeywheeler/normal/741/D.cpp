#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define U int('v'-'a'+1)

using namespace std;

int n;
vector<int> u[500005];
int p[500005];
int c[500005];
int m[500005];
int ts[500005];
int d[500005];

int dp[1<<U];
int ut[1<<U];
int T;

int res[500005];

void clr() {T++;}
void psh(int i) {if (ut[i] != T) dp[i] = -1e9, ut[i] = T;}

void go1(int i) {
    ts[i] = 1;
    for (int j : u[i]) d[j] = d[i]+1, go1(j), ts[i] += ts[j];
}

int qu(int i) {
    psh(m[i]);
    int rs = max(int(-1e9), d[i]+dp[m[i]]);
    FO(j,0,U) psh(m[i] ^ (1<<j)), rs = max(rs, d[i] + dp[m[i] ^ (1<<j)]);
    for (int j : u[i]) rs = max(rs,qu(j));
    return rs;
}

void st(int i) {
    psh(m[i]);
    dp[m[i]] = max(dp[m[i]], d[i]);
    for (int j : u[i]) st(j);
}

bool cmp(int i, int j) {
    return ts[i] < ts[j];
}

void go2(int i) {
    sort(u[i].begin(), u[i].end(), cmp);
    for (int j : u[i]) {
        clr(); go2(j);
    }
    int &ans = res[i] = 0;

    FO(ji,0,sz(u[i])) {
        int j = u[i][ji];
        ans = max(ans, res[j]);
        if (ji != sz(u[i])-1) {
            ans = max(ans, qu(j) - 2*d[i]);
            st(j);
        }
    }

    psh(m[i]);
    ans = max(ans, dp[m[i]] - d[i]);
    FO(j,0,U) psh(m[i] ^ (1<<j)), ans = max(ans, dp[m[i] ^ (1<<j)] - d[i]);

    psh(m[i]);
    dp[m[i]] = max(dp[m[i]], d[i]);
}

int main() {
    scanf("%d", &n);
    FO(i,1,n) {
        scanf("%d", p+i);
        u[--p[i]].push_back(i);
        char pc; scanf(" %c", &pc);
        c[i] = pc-'a';
        m[i] = m[p[i]] ^ (1<<c[i]);
    }
    go1(0);
    go2(0);
    FO(i,0,n) printf("%d%c", res[i], " \n"[i+1==n]);
}