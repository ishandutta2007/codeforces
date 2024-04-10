#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define pdd         pair<ld, ld>

#define eb          emplace_back
#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()
#define sz(a)       a.length()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;
const int N = 100005;

ld dis(pdd A, pdd B){
    return sqrt(pow(A.F-B.F, 2)+pow(A.S-B.S, 2));
}

pdd getlx(ld x, ld a, ld b, ld c){
    ld y = (-c-a*x)/b;
    return pdd(x, y);
}

pdd getly(ld y, ld a, ld b, ld c){
    ld x = (-c-b*y)/a;
    return pdd(x, y);
}

void solve(){
    ld a,b,c;
    pdd A, B, C;
    cin >> a >> b >> c >> A.F >> A.S >> B.F >> B.S;
    
    C.F = A.F;
    C.S = B.S;
    ld ans = dis(A, C)+dis(B, C);
    
    if (!a || !b) {cout << rnd(12) << ans; return ;}
    
    pdd X[2], Y[2];
    X[0] = getlx(A.F, a, b, c);
    X[1] = getly(A.S, a, b, c);
    Y[0] = getlx(B.F, a, b, c);
    Y[1] = getly(B.S, a, b, c);
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            ans = min(ans, dis(A, X[i])+dis(X[i], Y[j])+dis(Y[j], B));
        }
    }
    
    cout << rnd(12) << ans;
} 

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}