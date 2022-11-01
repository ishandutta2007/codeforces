#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int a;
string s;
int n;

ll Pref[4005];

ll Sum(int lo, int hi){return Pref[hi+1] - Pref[lo];}

map < ll, int > M;

int main(){
    cin >> a >> s;
    n = (int)s.size();
    REP(n,i) Pref[i+1] = Pref[i] + s[i] - '0';

    REP(n,i) REP(i+1,j) ++M[Sum(j,i)];
    ll R = 0;
    REP(n,i) REP(i+1,j) if (Sum(j,i) != 0 && a%Sum(j,i) == 0) R += M[a/Sum(j,i)];
    if (a == 0) R = 2 * (ll)M[0] * (n * (n+1) / 2) - (ll)M[0] * M[0];
    cout << R << endl;

    return 0;
}