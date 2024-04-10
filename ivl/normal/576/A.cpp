#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int erat[1005];

int main(){
    for (int i = 2; i <= 1000; ++i)
        if (erat[i] == 0)
            for (int j = i; j <= 1000; j += i) erat[j] = i;
    scanf("%d", &n);
    vector < int > V;
    FOR(2,n+1,i){
        int x = i, p = erat[i];
        while (x % p == 0) x /= p;
        if (x == 1) V.pb(i);
    } printf("%d\n", V.size());
    for (auto x : V) printf("%d ", x); printf("\n");
    return 0;
}