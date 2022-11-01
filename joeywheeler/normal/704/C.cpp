#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

vector<int> c[100005];
vector<int> v[100005];
int n, m;

int cs[100005];
int vs[100005];
int T;

void gv(int i);
void gc(int i) {
    cs[i] = ++T;
    for (int j : c[i]) if (!vs[abs(j)]) {
        gv(abs(j));
    }
}

void gv(int i) {
    vs[i] = ++T;
    for (int j : v[i]) if (!cs[abs(j)]) {
        gc(abs(j));
    }
}

int fcch[100005][2][2];

int fv(int i, int pt, int cp);
int fc(int i, bool s, int cp) {
    int &ans = fcch[i][s][cp];
    if (ans != -1) return ans;
    int nj = 0;
    for (int j : c[i]) if (vs[abs(j)] == cs[i]+1) nj = j;
    if (!nj) return ans = cp == 0;
    else return ans = fv(abs(nj), s ? 0 : (nj > 0 ? 1 : -1), cp);
}

int fvch[100005][3][2];
int fv(int i, int pt, int cp) {
    int &ans = fvch[i][pt+1][cp];
    if (ans != -1) return ans;
    int nj = 0;
    for (int j : v[i]) if (cs[abs(j)] == vs[i]+1) nj = j;
    ans = 0;
    for (int mv = -1; mv <= 1; mv += 2) {
        int ncp = cp;
        if (mv*pt == 1) ncp ^= 1;
        if (!nj) ans += ncp == 0;
        else {
            int nt = nj > 0 ? 1 : -1;
            if (nt * mv == 1) ncp ^= 1;
            ans += fc(abs(nj), nt*mv == 1, ncp);
        }
        if (ans >= MOD) ans -= MOD;
    }
    return ans;
}

int fccch[100005][2][2][2];

int fcv(int i, int pt, bool ls, int cp);
int fcc(int i, bool s, bool ls, int cp) {
    int &ans = fccch[i][s][ls][cp];
    if (ans != -1) return ans;

    int nj = 0;
    for (int j : c[i]) if (vs[abs(j)] == cs[i]+1) nj = j;
    if (!nj) return ans = (s || !ls) ? cp == 0 : cp == 1;
    else return ans = fcv(abs(nj), s ? 0 : (nj > 0 ? 1 : -1), ls, cp);
}

int fcvch[100005][3][2][2];

int fcv(int i, int pt, bool ls, int cp) {
    int &ans = fcvch[i][pt+1][ls][cp];
    int nj = 0;
    for (int j : v[i]) if (cs[abs(j)] == vs[i]+1) nj = j;
    ans = 0;
    for (int mv = -1; mv <= 1; mv += 2) {
        int ncp = cp;
        if (mv*pt == 1) ncp ^= 1;
        int nt = nj > 0 ? 1 : -1;
        if (nt * mv == 1) ncp ^= 1;
        ans += fcc(abs(nj), nt*mv == 1, ls, ncp);
        if (ans >= MOD) ans -= MOD;
    }
    return ans;
}

int f(int i, int cp) {
    int res = 0;
    for (int fv = -1; fv <= 1; fv += 2) {
        int nj = v[i][0], pj = v[i][1];
        int nt = (nj > 0 ? 1 : -1) * fv;
        int pt = (pj > 0 ? 1 : -1) * fv;
        int ncp = cp;
        if (nt == 1) ncp ^= 1;
        res += fcc(abs(nj), nt == 1, pt == 1, ncp);
        if (res >= MOD) res -= MOD;
    }
    return res;
}

void mrg(int &n0, int &n1, int m0, int m1) {
    int nn0 = (n0 * 1ll * m0 + n1 * 1ll * m1) % MOD;
    int nn1 = (n0 * 1ll * m1 + n1 * 1ll * m0) % MOD;
    n0 = nn0;
    n1 = nn1;
}

int main() {
    memset(fcch, -1, sizeof fcch);
    memset(fvch, -1, sizeof fvch);
    memset(fccch, -1, sizeof fccch);
    memset(fcvch, -1, sizeof fcvch);

    scanf("%d %d", &n, &m);
    FO(i,1,n+1) {
        int k; scanf("%d", &k);
        FO(z,0,k) {
            int x; scanf("%d", &x);
            int s = x > 0 ? 1 : -1;
            x = abs(x);
            c[i].push_back(s*x);
            v[x].push_back(s*i);
        }
    }
    int n0 = 1;
    int n1 = 0;
    FO(i,1,n+1) if (sz(c[i]) == 1 && !cs[i]) {
        gc(i);
        int m0 = fc(i,0,0);
        int m1 = fc(i,0,1);

        mrg(n0,n1,m0,m1);
    }
    FO(i,1,m+1) if (sz(v[i]) == 1 && !vs[i]) {
        gv(i);
        int m0 = fv(i,0,0);
        int m1 = fv(i,0,1);

        mrg(n0,n1,m0,m1);
    }
    FO(i,1,m+1) if (sz(v[i]) == 0) {
        vs[i] = ++T;
        n0 = (n0 * 2ll) % MOD;
        n1 = (n1 * 2ll) % MOD;
    }
    FO(i,1,m+1) if (!vs[i]) {
        gv(i);
        int m0 = f(i,0);
        int m1 = f(i,1);

        mrg(n0,n1,m0,m1);
    }

    printf("%d\n", n1);
}