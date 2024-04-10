#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
pair<int, int> dsu[1005];
int f(int x) {
    if(dsu[x].fi == x) return x;
    return dsu[x].fi = f(dsu[x].fi);
}
int aaa = 0;
int mx = 0;
int mxid = -1;
void join(int a, int b) {
    if(a > b) swap(a, b);
    if(f(a) == f(b)) {aaa++; return;}
    // if(aaa > 0 && f(a) != f(mxid) && f(b) != f(mxid)) {
    //     cerr << a << ' ' << b << ' ' << mxid << '\n';
    //     aaa--;
    //     join(a, mxid);
    //     join(b, mxid);
    //     return;
    // }
    int t = dsu[f(a)].se + dsu[f(b)].se;
    //cerr << t << ' ' << a << ' ' << f(a) << ' ' << b << ' ' << f(b) << '\n';
    dsu[f(a)].se = dsu[f(b)].se = t;
    // mx = max(mx, t);
    // if(t > mx) {
    //     mx = t;
    //     mxid = f(a);
    // }
    dsu[f(a)].fi = f(b);
}
void solve(int TC) {
    int n, d;
    cin >> n >> d;
    int a, b;
    for(int i = 1; i <= 1000; i++) dsu[i] = mp(i, 1);
    pair<int, int> dk[1005];
    for(int i = 0; i < d; i++) cin >> dk[i].fi >> dk[i].se;
    for(int i = 0; i < d; i++) {
        mx = 0, aaa = 0;
        for(int j = 1; j <= n; j++) dsu[j] = mp(j, 1);
        for(int j = 0; j <= i; j++) {
            join(dk[j].fi, dk[j].se);
        }
        vector<int> dkk;
        for(int j = 1; j <= n; j++) if(dsu[j].fi == j) dkk.pb(dsu[j].se);
        sort(dkk.begin(), dkk.end());
        reverse(dkk.begin(), dkk.end());
        int ans = 0;
        for(int j = 0; j <= aaa; j++) ans += dkk[j];
        cout << ans - 1 << '\n';
        // cout << mx + aaa - 1 << '\n';
    }
    // while(d--) {
    //     cin >> a >> b;
    //     join(a, b);
    //     int mx = 1;
    //     for(int i = 1; i <= n; i++) mx = max(mx, dsu[i].se - 1);
    //     cout << mx << '\n';
    // }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}