#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;

int gcd(int a, int b){
    while (b) a %= b, swap(a, b);
    return a;
}

int main(){
    scanf("%d", &n);
    multiset < int > S;
    REP(n*n,i){
        int x;
        scanf("%d", &x);
        S.insert(x);
    }
    vector < int > V;
    REP(n,i){
        int x = *(--S.end());
        for (auto y : V) REP(2,tt) S.erase(S.find(gcd(x, y)));
        V.pb(x);
        S.erase(S.find(x));
        printf("%d ", x);
    } printf("\n");
    return 0;
}