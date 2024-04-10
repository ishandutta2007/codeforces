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

const real ep = 1e-12;

real ccw(prr a, prr b, prr c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int n;
pii in[200005];
prr in2[200005];

int main(){
    scanf("%d", &n);
    REP(n,i) scanf("%d%d", &in[i].x, &in[i].y), in2[i] = {10000.0 / in[i].x, 10000.0 / in[i].y};
    set < prr > S;
    REP(n,i) S.insert(in2[i]);
    vector < prr > V;
    for (auto x : S){
        while ((int)V.size() >= 2){
            if (ccw(V[V.size()-2], V.back(), x) < -ep) V.pop_back();
            else break;
        } V.pb(x);
    }
    while (V.size() >= 2 && V.back().y >= V[V.size()-2].y) V.pop_back();
    S.clear();
    for (auto x : V) S.insert(x);
    REP(n,i) if (S.find(in2[i]) != S.end()) printf("%d ", i+1); printf("\n");
    return 0;
}