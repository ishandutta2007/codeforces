#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
vector < int > E[100005];

bool DFSl(int id, int p){
    static bool bio[100005];
    static bool memo[100005];
    bool &r = memo[id];
    if (bio[id]++) return r;
    vector < int > ch;
    for (auto x : E[id]) if (x != p) ch.pb(x);
    if (ch.size() == 0) return r = true;
    if (ch.size() > 1) return r = false;
    r = true;
    for (auto x : ch) if (!DFSl(x, id)) r = false;
    return r;
}

bool DFSlr(int id, int p){
    static bool bio[100005];
    static bool memo[100005];
    bool &r = memo[id];
    if (bio[id]++) return r;
    vector < int > ch;
    for (auto x : E[id]) if (x != p) ch.pb(x);
    if (ch.size() == 0) return r = true;
    if (ch.size() > 2) return r = false;
    r = true;
    for (auto x : ch) if (!DFSl(x, id)) r = false;
    return r;
}

bool DFSlrx(int id, int p){
    static bool bio[100005];
    static bool memo[100005];
    bool &r = memo[id];
    if (bio[id]++) return r;
    vector < int > ch;
    for (auto x : E[id]) if (x != p) ch.pb(x);
    if (ch.size() == 0) return r = true;
    vector < int > v;
    for (auto x : ch) if (!DFSlr(x, id)) v.pb(x);
    if (v.size() == 0) return r = true;
    if (v.size() > 1) return r = false;
    return r = DFSlrx(v.front(), id);
}

bool DFSlry(int id, int p){
    static bool bio[100005];
    static bool memo[100005];
    bool &r = memo[id];
    if (bio[id]++) return r;
    vector < int > ch;
    for (auto x : E[id]) if (x != p) ch.pb(x);
    if (ch.size() == 0) return r = true;
    vector < int > v;
    for (auto x : ch) if (!DFSlr(x, id)) v.pb(x);
    if (v.size() > 2) return r = false;
    if (v.size() == 0) return r = true;
    r = true;
    for (auto x : v) r &= DFSlrx(x, id);
    return r;
}

bool DFS(int id, int p){
    static bool bio[100005];
    static bool memo[100005];
    bool &r = memo[id];
    if (bio[id]++) return r;
    vector < int > ch;
    for (auto x : E[id]) if (x != p) ch.pb(x);
    if (ch.size() == 0) return r = true;
    vector < int > v;
    for (auto x : ch) if (!DFSlr(x, id)) v.pb(x);
    if (v.size() > 2) return r = false;
    if (v.size() == 0) return r = true;
    if (v.size() == 2) return r = (DFSlrx(v.front(), id) && DFSlrx(v.back(), id));
    int t = v.front();
    if (DFSlrx(t, id)) return r = true;
    if (ch.size() > 3) return r = false;
    int Cnt = 0;
    for (auto x : ch) if (DFSl(x, id)) ++Cnt;
    if (Cnt+1 != ch.size()) return r = false;
    return r = DFSlry(t, id);
}

int main(){
    scanf("%d", &n);
    REP(n-1,i){
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].pb(b);
        E[b].pb(a);
    }
    int x = -1;
    REP(n,i) if (E[i+1].size() > 2) x = i+1;
    if (x == -1 || DFS(x, x)) printf("Yes\n");
    else printf("No\n");
    return 0;
}