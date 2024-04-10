#include <cstdio>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <unistd.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pii pair < int, int >
#define x first
#define y second
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int a[10];
ll R;

bool T(int &a, int &b, int &c){
    if (a == 0 || b == 0 || c == 0) return false;
    R += 2 * b + 1;
    --a, --c;
    ++b;
}

int main(){
    REP(6,i) scanf("%d", a + i);
    REP(6,i) while (T(a[i], a[(i+1)%6], a[(i+2)%6]));
    REP(3,i) REP(i,j) R += a[i] * a[j] * 2;
    printf("%I64d\n", R);
    return 0;
}