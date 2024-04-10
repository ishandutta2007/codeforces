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
    int n;
    cin >> n;
    vector<int> c[n];
    vector<pii> ed;
    map<pii, int> mp;
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        ed.pb({u-1, v-1});
        c[u-1].pb(v-1);
        c[v-1].pb(u-1);
    }
    int l = 0, r = n-2;
    for (int i = 0; i < n-1; i++){
        int x = ed[i].F, y = ed[i].S;
        if (sz(c[x]) == 1 || sz(c[y]) == 1) {
            cout << l << endl;
            l ++;
        }else{
            cout << r << endl;
            r --;
        }
    }
}
int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}