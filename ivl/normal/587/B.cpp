#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define FORll(a,b,c) for (ll c = (ll)(a); c < (ll)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
ll l;
int k;
int a[1000005];

int b[1000005];
int len;

int c[1000005];

ll way[1000005];
const int Mod = 1000000007;

int main(){
    cin >> n >> l >> k;
    REP(n,i) scanf("%d", a+i), b[i] = a[i];
    //n = 100, k = 10000; l = 1000000000000000LL;
    sort(b, b+n);
    auto pt = unique(b, b+n);
    len = pt-b;
    REP(n,i) a[i] = lower_bound(b, pt, a[i]) - b;
    REP(n,i) ++c[a[i]];

    REP(n,i) way[i] = 1;
    ll R = 0;
    REP(k,ttt){
        FORll(max((ll)0, l-n), l, i){
            if (i/n < ttt) continue;
            R += way[a[i%n]] * ((i/n - ttt + 1) % Mod);
            R %= Mod;
        }
        REP(len,i) way[i] = (way[i] * c[i]) % Mod;
        FOR(1,len,i){
            way[i] += way[i-1];
            if (way[i] >= Mod) way[i] -= Mod;
        }
    } cout << R << endl;

    return 0;
}