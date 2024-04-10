#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>
#include <set>
#include <cstring>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define _T1 id * 2, lo, mid
#define _T2 id * 2 + 1, mid + 1, hi

using namespace std;

int n, k;
vector < int > V[100005];

int main(){
    scanf("%d%d", &n, &k);
    REP(k,i){
        int m;
        scanf("%d", &m);
        REP(m,j){
            int a;
            scanf("%d", &a);
            V[i].pb(a);
        }
    }
    int R = 0;
    for (auto &v : V){
        int p = 0;
        while (p < (int)v.size() && p + 1 == v[p]) ++p;
        R = max(R, p);
    } printf("%d\n", n - R + n - R - k + 1);
    return 0;
}