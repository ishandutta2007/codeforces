#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <cstring>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double
#define prr pair < real, real >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, q;
int f[100005];
vector < pii > E[100005];
pair < int, pii > Q[100005];

vector < pii > E2[100005];

int Size[100005];
pii Par[100005];
void Rootaj(int id, int p){
    Size[id] = 1;
    for (auto x : E[id]) if (x.x != p){
        E2[id].pb(x);
        Rootaj(x.x, id);
        Size[id] += Size[x.x];
        Par[x.x] = {id, x.y};
    }
}

class Node{
public:
    int l, r;
    int score;
    bool fill;
};
Node operator+(Node a, Node b){
    if (a.fill && b.fill) return {a.l + b.l, a.l + b.l, 0, true};
    if (a.fill) return {a.l + b.l, b.r, b.score, false};
    if (b.fill) return {a.l, a.r + b.r, a.score, false};
    return {a.l, b.r, a.score + b.score + f[a.r + b.l], false};
}
int Val(Node a){
    if (a.fill) return f[a.l];
    return a.score + f[a.l] + f[a.r];
}

const int offset = (1<<20);
Node T[offset * 2];
void Set(int id, int lo, int hi, int p, bool v){
    if (lo > p || hi < p) return;
    if (lo == hi){
        if (v) T[id] = {1, 1, 0, true};
        else T[id] = {0, 0, 0, false};
        return;
    }
    int m = (lo + hi) / 2;
    Set(id * 2, lo, m, p, v);
    Set(id * 2 + 1, m+1, hi, p, v);
    T[id] = T[id * 2] + T[id * 2 + 1];
}
void Set(int p, bool v){Set(1, 0, offset-1, p, v);}
Node Query(int id, int lo, int hi, int slo, int shi){
    if (lo > shi || hi < slo) return {0, 0, 0, true};
    if (lo >= slo && hi <= shi) return T[id];
    int m = (lo + hi) / 2;
    return Query(id*2, lo, m, slo, shi) + Query(id*2+1, m+1, hi, slo, shi);
}
Node Query(int lo, int hi){return Query(1, 0, offset-1, lo, hi);}

pii Ch[100005];
int clr[100005];
int pos[100005];
int ChDep[100005];
int root[100005];
void Heavy(int id, int chain){
    static int Cnt = 0;
    static int Cnt2 = 1;
    clr[id] = chain;
    pos[id] = Cnt++;
    Ch[chain].y = pos[id];
    if (E2[id].size() == 0) return;
    int opt = 0;
    REP(E2[id].size(),i) if (Size[E2[id][i].x] > Size[E2[id][opt].x]) opt = i;
    Heavy(E2[id][opt].x, chain);
    REP(E2[id].size(),i) if (i != opt){
        int ch2 = Cnt2++;
        ChDep[ch2] = ChDep[chain] + 1;
        root[ch2] = E2[id][i].x;
        Ch[ch2].x = Cnt;
        Heavy(E2[id][i].x, ch2);
    }
}

Node Flip(Node a){return {a.r, a.l, a.score, a.fill};}

Node Get(int A, int B){
    if (clr[A] == clr[B]){
        if (Size[A] > Size[B]) return Query(pos[A]+1, pos[B]);
        return Flip(Query(pos[B]+1, pos[A]));
    }
    if (ChDep[clr[A]] > ChDep[clr[B]]) return Flip(Query(Ch[clr[A]].x, pos[A])) + Get(Par[root[clr[A]]].x, B);
    else return Get(A, Par[root[clr[B]]].x) + Query(Ch[clr[B]].x, pos[B]);
}

int main(){
    scanf("%d%d", &n, &q);
    FOR(1,n,i) scanf("%d", f+i);
    REP(n-1,i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c), --a, --b;
        E[a].pb({b, c});
        E[b].pb({a, c});
    } Rootaj(0, 0);
    Heavy(0, 0);
    //REP(n,i) TRACE(i _ clr[i] _ pos[i]);
    REP(n,i) Set(i, true);
    REP(q,i) scanf("%d%d%d", &Q[i].y.x, &Q[i].y.y, &Q[i].x), --Q[i].y.x, --Q[i].y.y;
    vector < pii > V;
    REP(q,i) V.pb({Q[i].x, i});
    vector < pii > V2;
    REP(n,i) V2.pb({Par[i].y, i});
    sort(V.begin(), V.end());
    sort(V2.begin(), V2.end());
    vector < int > out(q);
    for (int i = 0, j = 0; i < (int)V.size(); ++i){
        while (j < (int)V2.size() && V2[j].x < V[i].x) Set(pos[V2[j].y], false), ++j;
        out[V[i].y] = Val(Get(Q[V[i].y].y.x, Q[V[i].y].y.y));
    }
    //REP(3,i) TRACE(i _ Query(pos[i], pos[i]).fill);
    //REP(3,i) TRACE(i _ Par[i].y);
    //for (auto x : V2) TRACE(x.x _ x.y);
    for (auto x : out) printf("%d\n", x);
    return 0;
}