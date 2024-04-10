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

const int offset = (1<<18);
int T[2*offset];
int TT[2*offset];
int TT2[2*offset];
void Set(int p, int v, int x){
    ++p;
    TT[p] = v, TT2[p] = x;
    for (int id = p; id < 200010 && v >= TT[T[id]]; id += id & -id) T[id] = p;
}
pii Max(int p){ ++p;
    int R = 0;
    for (; p; p &= (p-1)) if (TT[T[p]] > TT[R]) R = T[p];
    return {TT[R], TT2[R]};
}
int pret[200005];
void Rebuild(){
    FOR(1,200005,i){
        if (TT[T[pret[i]]] < TT[T[i]]) T[pret[i]] = T[i];
    }
}

int n;
int in[100005];
int m;
int fl[100005];

//int *Seq = T+1;
//int *Seq2 = T2+1;

int main(){
    FOR(1,200005,i) pret[i] = i + (i & -i);
    memset(TT2, -1, sizeof TT2);
    scanf("%d", &n);
    REP(n,i) scanf("%d", in+i);
    scanf("%d", &m);
    REP(m,i) scanf("%d", fl+i);
    sort(fl, fl+m);
    multiset < int > Back(fl, fl+m);
    int *poin = unique(fl, fl+m);
    m = (int)(poin-fl);

    vector < int > V;
    REP(n,i) if (in[i] != -1) V.pb(in[i]);
    REP(m,i) V.pb(fl[i]);
    sort(V.begin(), V.end());
    auto ttt = V.end() - unique(V.begin(), V.end());
    REP(ttt,i) V.pop_back();
    //TRACE(in[4]);
    //REP(V.size(),i) TRACE(V[i]);
    REP(n,i) if (in[i] != -1) in[i] = (int)(lower_bound(V.begin(), V.end(), in[i]) - V.begin());
    //TRACE(V[in[4]]);
    REP(m,i) fl[i] = (int)(lower_bound(V.begin(), V.end(), fl[i]) - V.begin());

    vector < int > Help(n);

    //cerr << " Start\n";
    REP(n,i){
        //REP(10,i) printf("%d ", TT[i]); printf("\n");
        //TRACE(Max(200005).x _ Max(200005).y);
        if (in[i] != -1){pii x = Max(in[i]-1); Help[i] = x.y; Set(in[i], 1+x.x, i); continue;}
        static int M;
        M = 0;
        for (int a = 0, b = 0; a < m; ++a, ++b){
            for (; b < fl[a]; ++b) if (TT[M] < TT[b+1]) M = b+1;
            if (TT[b+1] < TT[M]+1) TT[b+1] = TT[M]+1, TT2[b+1] = TT2[M], T[b+1] = b+1;
            else M = b+1;
        }
        Rebuild();
    } //cerr << " End\n";
    TRACE(Max(200005).x);
    REP(n,i) if (in[i] != -1) in[i] = V[in[i]];
    int End = Max(200005).y;
    vector < int > Sol;
    while (End != -1){
        Sol.pb(End);
        End = Help[End];
    } reverse(Sol.begin(), Sol.end());

    vector < int > Back2(fl, fl+m);
    REP(m,i) Back2[i] = V[Back2[i]];
    int pok = 0;
    vector < vector < int > > VV;
    vector < int > Fill;
    REP(Sol.size(),i){
        VV.pb({});
        while (pok < (int)Back2.size() && Back2[pok] < in[Sol[i]]) VV.back().pb(Back2[pok]), ++pok;
        while (pok < (int)Back2.size() && Back2[pok] == in[Sol[i]]) Fill.pb(Back2[pok]), ++pok;
        reverse(VV.back().begin(), VV.back().end());
    }
    VV.pb(vector < int >(Back2.begin()+pok, Back2.end()));
    reverse(VV.back().begin(), VV.back().end());

    vector < int > Out(in, in+n);
    //TRACE(in[4]);
    for (int a = 0, b = 0; a < n; ++a){
        if (b < (int)Sol.size() && a == Sol[b]) ++b;
        if (Out[a] == -1 && !VV[b].empty()) Out[a] = VV[b].back(), Back.erase(Back.find(VV[b].back())), VV[b].pop_back();
    }
    for (auto x : Back) VV[0].pb(x);
    for (int a = 0, b = 0; a < n; ++a){
        if (b < (int)Sol.size() && VV[b].empty()) ++b;
        if (Out[a] == -1) Out[a] = VV[b].back(), VV[b].pop_back();
    }

    for (auto x : Out) printf("%d ", x); printf("\n");

    return 0;
}