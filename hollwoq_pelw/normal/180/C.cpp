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
    string s;
    cin >> s;
    int n = len(s);
    int a[n+1], b[n+1];
    a[0] = 0;
    b[n] = 0;
    int m = INT_MAX;
    for (int l = 0; l < n; l++){
        a[l+1] = a[l] + (islower(s[l]) > 0);
    }
    for (int r = n-1;  r >= 0; r--){
        b[r] = b[r+1] + (isupper(s[r]) > 0);
    }
    for (int i = 0; i <= n; i++){
        //cout << a[i] << ' ' << b[i] << endl;
        m = min(m, a[i]+b[i]);
    }
    cout << m;
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}