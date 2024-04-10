#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

vector < ll > operator+(vector < ll > a, vector < ll > b){REP(3,i) a[i] += b[i]; return a;}
vector < ll > operator-(vector < ll > a, vector < ll > b){REP(3,i) a[i] -= b[i]; return a;}
void operator+=(vector < ll > &a, vector < ll > b){a = a + b;}
void operator-=(vector < ll > &a, vector < ll > b){a = a - b;}

multiset < multiset < ll > > MS;

ll d(vector < ll > a){
    return a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
}
bool good(vector < ll > a, vector < ll > b){
    if (!d(a)) return false;
    if (d(a) != d(b)) return false;
    if (d(a - b) != 2 * d(a)) return false;
    return true;
}

multiset < ll > f(vector < ll > v){
    multiset < ll > t;
    for (auto x : v) t.insert(x);
    return t;
}

void display(vector < ll > v){
    for (auto x : v) printf("%I64d ", x);
    printf("\n");
}

vector < multiset < ll > > VS;

void att(vector < ll > v, vector < ll > va, vector < ll > vb, vector < ll > vc){
    va -= v, vb -= v, vc -= v;
    if (!good(va, vb) || !good(va, vc) || !good(vc, vb)) return;
    if (d(va + vb + vc) != 3 * d(va)) return;
    static multiset < multiset < ll > > MS2;
    MS2.clear();
    MS2.insert(f(v));
    MS2.insert(f(v + va));
    MS2.insert(f(v + vb));
    MS2.insert(f(v + vc));
    MS2.insert(f(v + va + vb));
    MS2.insert(f(v + va + vc));
    MS2.insert(f(v + vb + vc));
    MS2.insert(f(v + va + vb + vc));
    if (MS2 != MS) return;
    printf("YES\n");
    vector < vector < ll > > VV;
    VV.pb(v);
    VV.pb(v + va);
    VV.pb(v + vb);
    VV.pb(v + vc);
    VV.pb(v + va + vb);
    VV.pb(v + va + vc);
    VV.pb(v + vb + vc);
    VV.pb(v + va + vb + vc);
    for (auto x : VS) REP(VV.size(),i){
        if (x != f(VV[i])) continue;
        display(VV[i]);
        VV.erase(VV.begin() + i);
        break;
    }
    exit(0);
}

void att(vector < ll > v, vector < ll > va, vector < ll > vb){
    for (auto x : MS){
        vector < ll > v2;
        for (auto y : x) v2.pb(y);
        REP(6,ttt){
            att(v, va, vb, v2);
            if (ttt & 1) swap(v2[0], v2[1]);
            else swap(v2[1], v2[2]);
        }
    }
}

void att(vector < ll > v, vector < ll > va){
    for (auto x : MS){
        vector < ll > v2;
        for (auto y : x) v2.pb(y);
        REP(6,ttt){
            att(v, va, v2);
            if (ttt & 1) swap(v2[0], v2[1]);
            else swap(v2[1], v2[2]);
        }
    }
}

int main(){
    REP(8,i){
        multiset < ll > t;
        REP(3,j){ll x; scanf("%I64d", &x); t.insert(x);}
        MS.insert(t);
        VS.pb(t);
    }
    multiset < ll > m1 = *MS.begin();
    vector < ll > v1;
    for (auto x : m1) v1.pb(x);
    for (auto x : MS){
        vector < ll > v2;
        for (auto y : x) v2.pb(y);
        REP(6,ttt){
            att(v1, v2);
            if (ttt & 1) swap(v2[0], v2[1]);
            else swap(v2[1], v2[2]);
        }
    } printf("NO\n");
    return 0;
}