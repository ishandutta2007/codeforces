#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int h[100005];
int l[100005], r[100005];

void Build(int *s){
    int cval = 1;
    REP(n,i){
        cval = min(cval, h[i]);
        s[i] = cval;
        ++cval;
    }
}

int main(){
    scanf("%d", &n);
    REP(n,i) scanf("%d", h+i);
    Build(l);
    reverse(h, h+n);
    Build(r);
    reverse(h, h+n);
    reverse(r, r+n);
    int R = 0;
    REP(n,i) R = max(R, min(l[i], r[i]));//, TRACE(l[i] _ r[i]);
    printf("%d\n", R);
    return 0;
}