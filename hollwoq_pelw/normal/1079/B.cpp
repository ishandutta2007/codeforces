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
#define sz(a)       a.length()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;
const int N = 100005;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    int a = 1, b;
    for ( ; a <= 5; a++){
        if ((n+a-1)/a > 20) continue;
        b = (n-1)/a+1; break;
    }
    cout << a << ' ' << b << endl;
    int c = a*b-n; //cout << c;
    int id = 0;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (i < c && j == 0) cout << '*';
            else cout << s[id++];
        }
        cout << endl;
    }
}

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}