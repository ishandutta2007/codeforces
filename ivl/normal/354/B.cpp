#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>

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

int n;
char T[25][25];
int V[25][25];

map < int, char > M[45];

char dp(int bit, int k){ // dp = a-b
    if (k == 2*n-2) return 0;
    if (M[k].count(bit)) return M[k][bit];
    char &r = M[k][bit];
    vector < int > V(26);
    REP(n,i) if ((bit >> i) & 1){ // x+y == k
        int x = i, y = k-i;
        if (x != n-1){
            int nx = x+1, ny = y;
            V[T[nx][ny]] |= (1<<nx);
        }
        if (y != n-1){
            int nx = x, ny = y+1;
            V[T[nx][ny]] |= (1<<nx);
        }
    }
    if (k%2 == 1){ // prvi igrac, oce da maxa
        r = -100;
        if (V[0]) r = max((int)r, 1 + dp(V[0], k+1));
        if (V[1]) r = max((int)r, -1 + dp(V[1], k+1));
        FOR(2,26,i) if (V[i]) r = max(r, dp(V[i], k+1));
    } else {
        r = 100;
        if (V[0]) r = min((int)r, 1 + dp(V[0], k+1));
        if (V[1]) r = min((int)r, -1 + dp(V[1], k+1));
        FOR(2,26,i) if (V[i]) r = min(r, dp(V[i], k+1));
    } return r;
}

int main(){
    scanf("%d", &n);
    REP(n,i) scanf("%s", T[i]);
    REP(n,i) REP(n,j){
        if (T[i][j] == 'a') V[i][j] = 1;
        else if (T[i][j] == 'b') V[i][j] = -1;
        else V[i][j] = 0;
        T[i][j] -= 'a';
    }
    int t = dp(1,0) + V[0][0];
    if (t > 0) printf("FIRST\n");
    if (t == 0) printf("DRAW\n");
    if (t < 0) printf("SECOND\n");
    return 0;
}