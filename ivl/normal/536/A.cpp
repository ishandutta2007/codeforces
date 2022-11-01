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

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int a, b, n;

ll f(int t){return a + (ll)(t - 1) * b;}
ll s(int t){return (f(t) + f(1)) * t / 2;}

void Solve(){
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);
    if (f(l) > t){printf("-1\n"); return;}
    ll lo = l, hi = 1000000000LL, mid = (lo + hi + 1) / 2;
    while (lo != hi){
        if (f(mid) > t || s(mid) - s(l-1) > (ll)t * m) hi = mid - 1;
        else lo = mid;
        mid = (lo + hi + 1) / 2;
    } printf("%d\n", (int)mid);
}

int main(){
    scanf("%d%d%d", &a, &b, &n);
    REP(n,i) Solve();
    return 0;
}