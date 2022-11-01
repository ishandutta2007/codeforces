#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>

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

int n, l, r, ql, qr;
int w[100005];

int F(int i){
    int a = i, b = n - i;
    int R = w[i] * l + r * (w[n] - w[i]);
    if (a > b){
        a -= b + 1;
        if (a > 0) R += ql * a;
    } else {
        b -= a + 1;
        if (b > 0) R += qr * b;
    } return R;
}

int main(){
    scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
    FOR(1,n+1,i) scanf("%d", w+i), w[i] += w[i-1];
    int R = (int)2e9;
    REP(n+1,i) R = min(R, F(i));
    printf("%d\n", R);
    return 0;
}