#include <bits/stdc++.h>

#define ll long long
#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

ll max(int x, ll y){if (x > y) return x; return y;}

ll F(ll x){if (x < 0) return 0; return (x+1) * (x+2) / 2;}

ll Solve(ll a, ll b, ll c, ll l){
    ll R = 0;
    R += F(l);
    ll s = a+b+c+l;
    R -= F(l - max(0,(s+1)/2-a));
    R -= F(l - max(0,(s+1)/2-b));
    R -= F(l - max(0,(s+1)/2-c));
    R += F(l - max(0,(s+1)/2-a) - max(0,(s+1)/2-b));
    R += F(l - max(0,(s+1)/2-c) - max(0,(s+1)/2-b));
    R += F(l - max(0,(s+1)/2-a) - max(0,(s+1)/2-c));
    R -= F(l - max(0,(s+1)/2-a) - max(0,(s+1)/2-b) - max(0,(s+1)/2-c));
    return R;
}

int main(){
    ll a, b, c, l;
    cin >> a >> b >> c >> l;
    ll R = 0;
    REP(l+1,i) R += Solve(a,b,c,i);
    cout << R << endl;
    return 0;
}