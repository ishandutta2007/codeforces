#include <bits/stdc++.h>

#define ll long long
#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, k;
int a[300005];

int xx, yy, t;

int f(int x, int y){return  x*(t+1) + y*t;}

bool bio[5005][5005];
int memo[5005][5005];
int dp(int x, int y){
    if (x == xx && y == yy) return 0;
    int &r = memo[x][y];
    if (bio[x][y]++) return r;
    r = 2000000005;
    if (x != xx) r = min(r, dp(x+1, y) + a[f(x+1,y)-1] - a[f(x,y)]);
    if (y != yy) r = min(r, dp(x, y+1) + a[f(x,y+1)-1] - a[f(x,y)]);
    return r;
}

int main(){
    scanf("%d%d", &n, &k);
    REP(n,i) scanf("%d", a+i);
    sort(a, a+n);
    xx = n%k, yy = k-xx, t = n/k;
    printf("%d\n", dp(0,0));
    return 0;
}