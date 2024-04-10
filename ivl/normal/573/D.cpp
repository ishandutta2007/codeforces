#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int oo = 1000000000;
const ll ool = (ll)oo * oo;

template < class T >
void makemax(T &a, T b){if (b > a) a = b;}

template < class T >
T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}

int n, q;
pii in[30005];

pii v1[30005], v2[30005];
int l1[30005], l2[30005];

ll Val[3][30005];

#define F(a,b) (v1[a].y != v2[b].y)
#define G(a,b) ((ll)v1[a].x * v2[b].x)

void Build(int p){
    if (p < 0) return;
    Val[0][p] = Val[1][p] = Val[2][p] = -ool;
    if (p < n && F(p, p)) Val[0][p] = G(p, p);
    if (p < n-1 && F(p, p+1) && F(p+1, p)) Val[1][p] = G(p, p+1) + G(p+1, p);
    if (p < n-2 && F(p, p+1) && F(p+1, p+2) && F(p+2, p)) Val[2][p] = G(p, p+1) + G(p+1, p+2) + G(p+2, p);
    if (p < n-2 && F(p, p+2) && F(p+1, p) && F(p+2, p+1)) makemax(Val[2][p], G(p, p+2) + G(p+1, p) + G(p+2, p+1));
}

ll memo[30005];
ll dp(int p){
    return memo[p] = max(-ool, Val[0][p] + memo[p+1], Val[1][p] + memo[p+2], Val[2][p] + memo[p+3]);
}

int main(){
    scanf("%d%d", &n, &q);
    REP(n,i) scanf("%d", &in[i].x), v1[i] = {in[i].x, i};
    REP(n,i) scanf("%d", &in[i].y), v2[i] = {in[i].y, i};
    sort(v1, v1+n);
    sort(v2, v2+n);
    REP(n,i) l1[v1[i].y] = l2[v2[i].y] = i;
    REP(n,i) Build(i);
    for (int i = n-1; i >= 0; --i) dp(i);
    REP(q,i){
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        swap(l2[a], l2[b]), swap(v2[l2[a]].y, v2[l2[b]].y);
        REP(3,ii) Build(l2[a]-ii), Build(l2[b]-ii);
        for (int j = max(l2[a], l2[b]); j >= 0; --j) dp(j);
        printf("%I64d\n", memo[0]);
    }
    return 0;
}