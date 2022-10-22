#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// input, output
#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)
// pair
#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define pdd         pair<ld, ld>
// vector & !!?(string)
#define eb          emplace_back
#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()
#define len(a)      a.length()
// geometry calc
#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;

void solve(){
    ll res = 0;
    vector<int> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        if (t % 2) s.pb(t);
        else if (t > 0) res += t;
    }
    sort(rall(s));
    res += s[0];
    int i = 1;
    while(i < sz(s)-1){
        if (s[i]+s[i+1] > 0) res += s[i]+s[i+1];
        else break;
        i += 2;
    }
    cout << res;
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}