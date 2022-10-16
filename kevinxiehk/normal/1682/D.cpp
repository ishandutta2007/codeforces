#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
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
void solve(int TC) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(auto x: s) cnt += x - '0';
    if(cnt % 2 == 1 || cnt == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    set<pair<int, int>> op;
    set<int> one;
    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == '0') op.insert(mp(i, 0));
        else {
            op.insert(mp(i, 1));
            one.insert(i);
        }
    }
        // cout << op.size() << '\n';
    for(int _ = 1; _ < n; _++) {
        int x = (*one.begin());
        auto r = op.lower_bound(mp(x, -1));
        auto l = r;
        auto r2 = r;
        ++r2;
        if(r == op.begin()) {
            r = op.end();
            --r;
        }
        else --r;
        if(r2 == op.end()) r2 = op.begin();
        pair<int, int> ll = *l, rr = *r, rr2 = *r2;
        if(rr2.se == 1) swap(rr, rr2);
        if(rr.se == 1 && one.size() == 2 && _ != n - 1) swap(rr, rr2);
        if(rr.se == 0) {
            cout << ll.fi << ' ' << rr.fi << '\n';
            one.erase(ll.fi);
            one.insert(rr.fi);
            op.erase(ll);
            op.erase(rr);
            op.insert(mp(rr.fi, 1));
        }
        else {
            cout << ll.fi << ' ' << rr.fi << '\n';
            one.erase(ll.fi);
            one.erase(rr.fi);
            op.erase(ll);
            op.erase(rr);
            op.insert(mp(rr.fi, 0));
        }
        // cout << op.size() << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}