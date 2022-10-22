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
#define len(a)      a.length()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;

void solve(){
    string s;  int n;
    ll a, b, sum;
    cin >> n >> a >> b >> s;
    
    sum = (n+1)*b+n*a;
    int l, r;    
    for (l = 0; l < n; l++){
        if (s[l] == '1') break;
    }
    for (r = n-1; r >= 0; r--){
        if (s[r] == '1') break;
    }
    //cout << l << ' ' << r << endl;
    if (l > r) {cout << sum << endl; return ;}
    sum += 2*a;
    int c0 = 0, c1 = 0;
    for (int i = l; i <= r; i++){
        if (s[i] == '0'){
            c0 ++;
            if (c1 > 0) sum += b*(c1+1);
            c1 = 0;
        }
        if (s[i] == '1'){
            c1 ++;
            if (c0 > 1) sum += min(2*a, (c0-1)*b);
            c0 = 0;
        }
    }
    sum += b*(c1+1);
    cout << sum << endl;
}

int main(){
    IOS;
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}