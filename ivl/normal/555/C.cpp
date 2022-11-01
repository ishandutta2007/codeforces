#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>
#include <set>
#include <cstring>
#include <map>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define _T1 id * 2, lo, mid
#define _T2 id * 2 + 1, mid + 1, hi
#define pll pair < ll, ll >

using namespace std;

int f(vector < int > &v, int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

const int oo = 1000000005;

const int offset = (1 << 19);
class Klasa{
public:
    int T[2 * offset];
    Klasa(){
        for (auto &x : T) x = oo;
    }
    void prop(int id){
        if (T[id] == oo) return;
        T[id * 2] = min(T[id * 2], T[id]);
        T[id * 2 + 1] = min(T[id * 2 + 1], T[id]);
        T[id] = oo;
    }
    void Set(int id, int lo, int hi, int slo, int shi, int v){
        if (lo > shi || hi < slo) return;
        if (lo >= slo && hi <= shi){T[id] = min(T[id], v); return;}
        prop(id);
        int mid = (lo + hi) / 2;
        Set(_T1, slo, shi, v);
        Set(_T2, slo, shi, v);
    }
    void Set(int lo, int hi, int v){Set(1, 0, offset - 1, lo, hi, v);}
    int Query(int id, int lo, int hi, int p){
        if (lo > p || hi < p) return oo;
        if (lo == hi) return T[id];
        int mid = (lo + hi) / 2;
        prop(id);
        return min(Query(_T1, p), Query(_T2, p));
    }
    int Query(int p){return Query(1, 0, offset - 1, p);}
} K[2];

int n, q;
pair < int, bool > ev[200005];

char str[10];
int main(){
    scanf("%d%d", &n, &q);
    vector < int > V;
    REP(q,i){
        int x, y;
        scanf("%d%d%s", &x, &y, str);
        bool t = (*str == 'L');
        if (t) x = n + 1 - x;
        ev[i] = {x, t};
        V.pb(x), V.pb(n + 1 - x);
    } V.pb(0), V.pb(oo);
    sort(V.begin(), V.end());
    int l = unique(V.begin(), V.end()) - V.begin();
    while ((int)V.size() > l) V.pop_back();
    K[0].Set(0, offset - 1, n);
    K[1].Set(0, offset - 1, n);
    REP(q,i){
        int x = ev[i].x;
        bool t = ev[i].y;
        int v = K[t].Query(f(V, x));
        K[!t].Set(f(V, n + 1 - v), f(V, n + 1 - x), n - x);
        K[t].Set(f(V, x), f(V, x), x - 1);
        printf("%d\n", v - x + 1);
    }
    return 0;
}