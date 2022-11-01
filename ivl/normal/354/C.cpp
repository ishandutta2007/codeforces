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

void Fin(int x){printf("%d\n", x); exit(0);}

int n, k;
int a[300005];

int p[3000005];

int main(){
    scanf("%d%d", &n, &k);
    REP(n,i) scanf("%d", a+i), ++p[a[i]];
    REP(3000004,i) p[i+1] += p[i];
    sort(a, a+n);
    if (a[0] <= k+1) Fin(a[0]);
    int r = k+1;
    //REP(20,i) TRACE(i _ p[i]);
    FOR(k+2,1000001,i){
        int Cnt = 0;
        for (int j = i; j < 2000005; j += i) Cnt += p[j+k] - p[j-1];
        //if (i <= 10) TRACE(i _ Cnt);
        if (Cnt == n) r = i;
    } printf("%d\n", r);
    return 0;
}