#include <bits/stdc++.h>

#define ll long long
#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int offset = 1<<19;

ll Sum[offset*2];
void Add(int id, int lo, int hi, int slo, int shi, ll val){
    if (lo > shi || hi < slo) return;
    if (lo >= slo && hi <= shi){Sum[id] += val; return;}
    int m = (lo+hi) / 2;
    Add(id*2, lo, m, slo, shi, val);
    Add(id*2+1, m+1, hi, slo, shi, val);
}
void Add(int lo, int hi, ll val){Add(1, 0, offset-1, lo, hi, val);}
ll Query(int id, int lo, int hi, int p){
    if (lo > p || hi < p) return 0;
    if (lo == hi) return Sum[id];
    int m = (lo+hi) / 2;
    return Sum[id] + Query(id*2, lo, m, p) + Query(id*2+1, m+1, hi, p);
}
ll Query(int p){return Query(1, 0, offset-1, p);}

class Query{
public:
    int t, x, y;
} Q[500005];

int n, m;

vector < int > Order(int t){
    vector < int > V[500005];
    REP(n+1,i) V[i].pb(i);
    REP(m,i) if (Q[i].t == t){
        int a = Q[i].x, b = Q[i].y;
        if (V[a].size() >= V[b].size()){
            for (auto x : V[b]) V[a].pb(x);
            V[b].clear();
        } else {
            for (auto x : V[a]) V[b].pb(x);
            V[a].clear();
            swap(V[a], V[b]);
        }
    }
    vector < int > R;
    for (auto &x : V) for (auto y : x) R.pb(y);
    return R;
}

vector < int > Inv(vector < int > V){
    vector < int > R(V.size());
    REP(V.size(),i) R[V[i]] = i;
    return R;
}

vector < int > Ord[2][2];
pii Zgr[2][500005];

pii Merge(pii a, pii b){return {min(a.x, b.x), max(a.y, b.y)};}

int Back[offset*2];
void Propagiraj(int id){
    if (Back[id] == -1) return;
    Back[id*2] = Back[id*2+1] = Back[id];
    Back[id] = -1;
}
void Set(int id, int lo, int hi, int slo, int shi, int v){
    if (lo > shi || hi < slo) return;
    if (lo >= slo && hi <= shi){Back[id] = v; return;}
    Propagiraj(id);
    int m = (lo+hi) / 2;
    Set(id*2, lo, m, slo, shi, v);
    Set(id*2+1, m+1, hi, slo, shi, v);
}
void Set(int lo, int hi, int v){Set(1, 0, offset-1, lo, hi, v);}
int Get(int id, int lo, int hi, int p){
    if (lo > p || hi < p) return -1;
    if (Back[id] != -1) return Back[id];
    int m = (lo+hi) / 2;
    return max(Get(id*2, lo, m, p), Get(id*2+1, m+1, hi, p));
}
int Get(int p){return Get(1, 0, offset-1, p);}

ll Out[500005];

vector < int > Vek[500005];

int main(){
    scanf("%d%d", &n, &m);
    REP(m,i){
        char c[5];
        scanf("%s", c);
        if (c[0] == 'U'){
            Q[i].t = 0;
            scanf("%d%d", &Q[i].x, &Q[i].y);
        }
        if (c[0] == 'M'){
            Q[i].t = 1;
            scanf("%d%d", &Q[i].x, &Q[i].y);
        }
        if (c[0] == 'A'){
            Q[i].t = 2;
            scanf("%d", &Q[i].x);
        }
        if (c[0] == 'Z'){
            Q[i].t = 3;
            scanf("%d", &Q[i].x);
        }
        if (c[0] == 'Q'){
            Q[i].t = 4;
            scanf("%d", &Q[i].x);
        }
    }
    REP(2,i) Ord[i][0] = Order(i), Ord[i][1] = Inv(Ord[i][0]);
    REP(2,t) REP(n+1,i) Zgr[t][i] = {Ord[t][1][i], Ord[t][1][i]};

    int Cnt = 0;
    REP(m,i){
        int a = Q[i].x, b = Q[i].y, t = Q[i].t;
        if (t <= 1) Zgr[t][a] = Merge(Zgr[t][a], Zgr[t][b]);
        if (t == 2) ++Cnt, Add(Zgr[0][a].x, Zgr[0][a].y, Zgr[0][a].y - Zgr[0][a].x + 1);
        if (t == 3) Set(Zgr[1][a].x, Zgr[1][a].y, Cnt);
        if (t == 4){
            //printf("%I64d\n", T.Query(Ord[0][1][a]) - T.Query(Get(Ord[1][1][a]), Ord[0][1][a]));
            Out[i] += Query(Ord[0][1][a]);
            Vek[Get(Ord[1][1][a])].pb(i);
        }
    }
    memset(Sum, 0, sizeof Sum);
    memset(Back, 0, sizeof Back);
    REP(n+1,i) Zgr[0][i] = {Ord[0][1][i], Ord[0][1][i]};
    Cnt = 0;
    REP(m,i){
        int a = Q[i].x, b = Q[i].y, t = Q[i].t;
        if (t <= 1) Zgr[t][a] = Merge(Zgr[t][a], Zgr[t][b]);
        if (t == 2){
            Add(Zgr[0][a].x, Zgr[0][a].y, Zgr[0][a].y - Zgr[0][a].x + 1);
            ++Cnt;
            for (auto x : Vek[Cnt]) Out[x] -= Query(Ord[0][1][Q[x].x]);
        }
    }
    REP(m,i) if (Q[i].t == 4) printf("%I64d\n", Out[i]);
    return 0;
}