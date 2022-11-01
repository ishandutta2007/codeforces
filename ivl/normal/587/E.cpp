#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define FORll(a,b,c) for (ll c = (ll)(a); c < (ll)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void reduciraj(vector < int > &v){
    int Cnt = 0;
    for (int i = 29; i >= 0; --i){
        int id = -1;
        FOR(Cnt, v.size(), j) if ((v[j]>>i)&1){id = j; break;}
        if (id == -1) continue;
        swap(v[Cnt], v[id]);
        REP(v.size(), j) if (j != Cnt && ((v[j]>>i)&1)) v[j] ^= v[Cnt];
        ++Cnt;
    }
    while (!v.empty() && v.back() == 0) v.pop_back();
}

void minaj(int &a, vector < int > &v){
    for (auto x : v) if ((a^x) < a) a ^= x;
}

int n, q;
const int offset = (1<<18);
int a[offset];

vector < int > T[offset*2];
int Tm[offset*2];
int P[offset*2];
void make(int id){
    T[id].clear();
    for (auto x : T[id*2]) T[id].pb(x);
    for (auto x : T[id*2+1]) T[id].pb(x);
    T[id].pb(Tm[id*2]^Tm[id*2+1]);
    reduciraj(T[id]);
    Tm[id] = (Tm[id*2]^P[id]);
    minaj(Tm[id], T[id]);
}
void init(int id, int lo, int hi){
    if (lo == hi){
        T[id] = {};
        Tm[id] = a[lo];
        return;
    }
    int m = (lo+hi)/2;
    init(id*2, lo, m);
    init(id*2+1, m+1, hi);
    make(id);
}

void propagiraj(int id){
    int t = P[id];
    P[id] = 0;
    Tm[2*id] ^= t;
    P[2*id] ^= t;
    minaj(Tm[id*2], T[id*2]);
    Tm[2*id+1] ^= t;
    P[2*id+1] ^= t;
    minaj(Tm[id*2+1], T[id*2+1]);
}

void update(int id, int lo, int hi, int slo, int shi, int k){
    if (lo > shi || hi < slo) return;
    if (lo >= slo && hi <= shi){
        P[id] ^= k;
        Tm[id] ^= k;
        minaj(Tm[id], T[id]);
        return;
    } propagiraj(id);
    int m = (lo+hi)/2;
    update(id*2, lo, m, slo, shi, k);
    update(id*2+1, m+1, hi, slo, shi, k);
    make(id);
}
void update(int lo, int hi, int k){update(1, 0, offset-1, lo, hi, k);}

vector < int > qv;
int qm;
void calc(int id, int lo, int hi, int slo, int shi){
    if (lo > shi || hi < slo) return;
    if (lo >= slo && hi <= shi){
        for (auto x : T[id]) qv.pb(x);
        if (qm != -1) qv.pb(qm^Tm[id]);
        reduciraj(qv);
        qm = Tm[id];
        minaj(qm, qv);
        return;
    } propagiraj(id);
    int m = (lo+hi)/2;
    calc(id*2, lo, m, slo, shi);
    calc(id*2+1, m+1, hi, slo, shi);
}
void calc(int lo, int hi){qm = -1; qv.clear(); calc(1, 0, offset-1, lo, hi);}

int main(){
    cin >> n >> q;
    REP(n,i) scanf("%d", a+i);
    init(1, 0, offset-1);
    /*calc(0,4);
    for (auto x : qv) TRACE(x);
    return 0;*/
    REP(q,i){
        int t;
        scanf("%d", &t);
        if (t == 1){
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k), --l, --r;
            update(l, r, k);
        } else {
            int l, r;
            scanf("%d%d", &l, &r), --l, --r;
            calc(l, r);
            if (qm) printf("%d\n", 2<<(qv.size()));
            else printf("%d\n", 1<<(qv.size()));
        }
    }
    return 0;
}