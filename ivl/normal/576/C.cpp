#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;

vector < pair < pii, int > > V[1005];

int main(){
    scanf("%d", &n);
    REP(n,i){
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        V[b/1000].pb({{a, b}, i+1});
    }
    REP(1000,i) sort(V[i].begin(), V[i].end());
    REP(500,i) reverse(V[2*i].begin(), V[2*i].end());
    for (auto &x : V) for (auto y : x) printf("%d ", y.y); printf("\n");
    return 0;
}