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
const int N = 100005, M = 200010;

void solve(){
    int n; cin >> n;
    int a[n+3];
    a[0] = 0;
    a[n+1] = 1001;
    a[n+2] = 1e5;
    for (int i = 1; i <= n; i++) cin >> a[i];    
    
    int c = 0, total = 0;
    for (int i = 1; i < n+3; i++){
        if (a[i] == a[i-1]+1){
            c ++;
        }else{
            if (c) total = max(total, c-1);
            c = 0;
        }
        // cout << c << endl;
    }
    cout << total;
} 

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}