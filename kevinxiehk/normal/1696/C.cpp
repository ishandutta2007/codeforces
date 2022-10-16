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
    vector<pair<int, int>> a, b;
    int n, m;
    cin >> n >> m;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        int tt = t;
        while(tt % m == 0) tt /= m;
        if(!a.empty() && a[a.size() - 1].fi == tt) a[a.size() - 1].se += t / tt;
        else a.pb(mp(tt, t / tt));
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        int tt = t;
        while(tt % m == 0) tt /= m;
        if(!b.empty() && b[b.size() - 1].fi == tt) b[b.size() - 1].se += t / tt;
        else b.pb(mp(tt, t / tt));
    }
    if(a.size() != b.size()) {
        cout << "No\n";
        return;
    }
    n = a.size();
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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