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

#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;
const int N = 100005;

void solve() {
    int n, k, a[101];
    cin >> n >> k;
    int mx = 0;
    ms0(a);
    for(int  i = 1;i <= n; i++){
        int x; cin >> x;
        a[x]++;
        mx = max(mx, a[x]);
    }
    int ans = 0;
    mx = (mx + k - 1) / k;
    for(int i = 1;i <= 100; i++){
        if(a[i] != 0){
            ans += mx*k - a[i];
        }
    }
    cout<<ans;
}

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}