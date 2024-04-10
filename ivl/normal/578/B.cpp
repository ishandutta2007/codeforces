#include <bits/stdc++.h>

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

int n, k, x;
ll a[200005];
ll Pref[200005];
ll Suff[200005];

int main(){
    scanf("%d%d%d", &n, &k, &x);
    REP(n,i) scanf("%I64d", a+i);
    REP(n,i) Pref[i+1] = (Pref[i] | a[i]);
    REP(n,i) Suff[i+1] = (Suff[i] | a[n-1-i]);
    ll Lift = 1;
    REP(k,i) Lift *= x;
    ll R = 0;
    REP(n,i) R = max(R, Pref[i] | (a[i] * Lift) | Suff[n-1-i]);
    printf("%I64d\n", R);
    return 0;
}