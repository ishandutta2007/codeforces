#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n;
int p[MAXN], ofs[MAXN];
int dub[MAXN], r[MAXN], lef[MAXN], rig[MAXN], par[MAXN];
int sol[2][MAXN];
vector <int> v;

void build (int tip) {
    for (int i=1; i<=n; i++) {
        dub[i] = r[i] = lef[i] = rig[i] = par[i] = 0;
    }
    dub[1] = 1; r[1] = 0;
    sol[tip][1] = 1;
    int curr = 1, res = 1;
    for (auto x : v) {
        while (curr >= x) {
            curr = par[curr];
            dub[curr] = 1 + max(dub[lef[curr]], dub[rig[curr]]);
        }
        int pp = curr, rr = rig[curr];
        par[x] = pp; rig[pp] = x;
        par[rr] = x; lef[x] = rr;
        dub[x] = 1 + dub[rr];
        r[x] = r[pp] + 1;
        res = max(res, dub[x] + r[x]);
        sol[tip][x] = res;
        curr = x;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int pos = 0, cnt = 0;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        if (p[i] == 1) pos = i; else ofs[i] = ++cnt;
    }
    for (int i = pos + 1; i <= n; i++) v.push_back(p[i]);
    for (int i = 1; i <= pos - 1; i++) v.push_back(p[i]);
    build(0);
    reverse(v.begin(), v.end());
    build(1);
    int mn = n + 1, ind = 0;
    for (int i=1; i<=n; i++) {
        //cout << "bla " << p[i] << " " << sol[0][p[i]] << " " << sol[1][p[i]] << endl;
        int nxt = i + 1;
        if (i == n) nxt = 1;
        int val = max(sol[0][p[i]], sol[1][p[nxt]]);
        if (val < mn) {
            mn = val;
            ind = i;
        }
    }
    cout << mn << " " << ind % n;
    return 0;
}