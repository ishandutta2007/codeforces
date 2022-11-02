#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, t;
int a[105];

int DP(int lo, int hi, int pos){ // 100, 100, 100
    static int memo[105][105][105];
    static bool bio[105][105][105];
    int &r = memo[lo][hi][pos];
    if (bio[lo][hi][pos]++) return r;
    if (lo > hi) return r = -1000000000;
    if (pos == n) return r = 0;
    r = DP(lo, hi, pos+1);
    if (a[pos] >= lo && a[pos] <= hi) r = max(r, 1+DP(a[pos], hi, pos+1));
    return r;
}

int mat[105][105];
int R[105][105];

int P[105][105];

void makemax(int &a, int b){if (a < b) a = b;}

int main(){
    scanf("%d%d", &n, &t);
    REP(n,i) scanf("%d", a+i);
    vector < int > V(a, a+n);
    sort(V.begin(), V.end());
    int Bla = unique(V.begin(), V.end()) - V.begin();
    while (V.size() > Bla) V.pop_back();
    REP(n,i) a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
    REP(101,i) REP(101,j) mat[i][j] = DP(i, j, 0);
    //  REP(4,i) REP(4,j) TRACE(i _ j _ mat[i][j]);

    REP(30,bit){
        if ((t>>bit) & 1){
            REP(101,i) FOR(i,101,j) FOR(i,j+1,k) makemax(P[i][j], R[i][k] + mat[k][j]);
            REP(101,i) REP(101,j) R[i][j] = P[i][j], P[i][j] = 0;
        }
        REP(101,i) FOR(i,101,j) FOR(i,j+1,k) makemax(P[i][j], mat[i][k] + mat[k][j]);
        REP(101,i) REP(101,j) mat[i][j] = P[i][j], P[i][j] = 0;
    }
    int r = 0;
    REP(101,i) REP(101,j) r = max(r, R[i][j]);
    printf("%d\n", r);
    return 0;
}