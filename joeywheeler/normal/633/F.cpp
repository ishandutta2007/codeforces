#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

set<int> u[100005];
vector<int> v;
int ts[100005];
int mxs[100005];
ll mxrl[100005]; // root leaf
ll mxgp[100005]; // general p
ll f[100005]; // weird thing
ll ndv[100005]; // nd val
int n;

void cs(int i, int par) {
    v.push_back(i);
    ts[i] = 1; mxs[i] = 0;
    mxrl[i] = mxgp[i] = f[i] = 0;
    for (int j : u[i]) if (j != par) {
        cs(j,i);
        ts[i] += ts[j];
        mxs[i] = max(mxs[i], ts[j]);
    }
}

void cl(int i, int par) {
    multiset<pair<ll,int> > s;
    s.emplace(0,-1);
    s.emplace(0,-2);
    multiset<pair<ll,int> > t;
    t.emplace(0,-1);
    t.emplace(0,-2);

    mxrl[i] = mxgp[i] = f[i] = ndv[i];

    for (int j : u[i]) if (j != par) {
        cl(j,i);

        mxrl[i] = max(mxrl[i], mxrl[j] + ndv[i]);
        mxgp[i] = max(mxgp[i], mxgp[j]);
        f[i] = max(f[i], f[j] + ndv[i]);
        s.emplace(mxrl[j],j);
        s.erase(s.begin());

        t.emplace(mxgp[j],j);
        t.erase(t.begin());
    }

    mxgp[i] = max(mxgp[i], s.begin()->first+s.rbegin()->first+ndv[i]);
    for (auto p1 : s) for (auto p2 : t) {
        if (p1.second != p2.second) {
            f[i] = max(f[i], ndv[i] + p1.first + p2.first);
        }
    }
}

ll ans = 0;

void decomp(int r) {
    v.clear(); cs(r,0);
    for (int x : v) mxs[x] = max(mxs[x], ts[r]-ts[x]);
    for (int x : v) if (mxs[x] < mxs[r]) r = x;
    cl(r,0);

    multiset<pair<ll,int> > g;
    g.emplace(0,-1); g.emplace(0,-2); g.emplace(0,-3);
    multiset<pair<ll,int> > s;
    s.emplace(0,-1); s.emplace(0,-2); s.emplace(0,-3);
    multiset<pair<ll,int> > t;
    t.emplace(0,-1); t.emplace(0,-2); t.emplace(0,-3);

    for (int j : u[r]) {
        g.emplace(mxgp[j],j);
        s.emplace(mxrl[j],j);
        t.emplace(f[j],j);

        g.erase(g.begin());
        s.erase(s.begin());
        t.erase(t.begin());
    }

    for (auto p1 : g) for (auto p2 : g) {
        if (p1.second != p2.second) {
            ans = max(ans, p1.first+p2.first);
        }
    }

    for (auto p1 : s) for (auto p2 : s) for (auto p3 : g) {
        if (p1.second != p2.second && p1.second != p3.second && p2.second != p3.second) {
            ans = max(ans, p1.first+p2.first+p3.first+ndv[r]);
        }
    }

    for (auto p1 : s) for (auto p2 : t) {
        if (p1.second != p2.second) {
            ans = max(ans, p1.first+p2.first+ndv[r]);
        }
    }

    for (int j : u[r]) {
        u[j].erase(r);
        decomp(j);
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", ndv+i+1);
    FO(i,0,n-1) {
        int x , y; scanf("%d%d", &x, &y);
        u[x].insert(y);
        u[y].insert(x);
    }
    decomp(1);
    printf("%lld\n", ans);
}