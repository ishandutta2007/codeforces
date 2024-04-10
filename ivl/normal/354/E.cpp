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

ll n;
int seq[25];

char memo[25][100];
bool dp(int id, int v){ //TRACE(id _ v);
    if (id == -1) return (v == 0);
    v = v * 10 + seq[id];
    if (v > 50 || v < 0) return false;
    char &r = memo[id][v];
    if (r) return r-1;
    REP(7,a) REP(7-a,b) r |= dp(id-1, v - 4*a - 7*b);
    return r++;
}

ll num[10];
void rek(int id, int v){
    if (id == -1) return;
    v = v * 10 + seq[id];
    REP(7,a) REP(7-a,b) if (dp(id-1, v - 4*a - 7*b)){
        int x = 0;
        REP(a,i) num[x] = num[x] * 10 + 4, ++x;
        REP(b,i) num[x] = num[x] * 10 + 7, ++x;
        REP(6-a-b,i) num[x] = num[x] * 10, ++x;
        rek(id-1, v - 4*a - 7*b);
        return;
    }
}

void Solve(){
    scanf("%I64d", &n);
    memset(seq, 0, sizeof seq);
    memset(num, 0, sizeof num);
    memset(memo, 0, sizeof memo);
    for (int i = 0; n; ++i, n /= 10) seq[i] = n%10;
    bool t = dp(22, 0);
    if (!t){printf("-1\n"); return;}
    rek(22, 0);
    REP(6,i) printf("%I64d ", num[i]); printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    REP(t,i) Solve();
    return 0;
}