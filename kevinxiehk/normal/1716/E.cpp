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

// standard segtree

struct node{
    int ans, lmax, rmax, sum = 0;
};
vector<vector<node>> solve[20];
void sol(int TC) {
    int k;
    cin >> k;
    int n = (1 << k);
    int arr[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        node t;
        t.ans = max(0LL, arr[i]);
        t.lmax = max(0LL, arr[i]);
        t.rmax = max(0LL, arr[i]);
        t.sum = arr[i];
        vector<node> tt; tt.pb(t);
        solve[0].pb(tt);
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < solve[i - 1].size(); j += 2) {
            vector<node> tt;
            for(int k = 0; k < solve[i - 1][j].size(); k++) {
                node t, l, r;
                l = solve[i - 1][j][k];
                r = solve[i - 1][j + 1][k];
                t.lmax = max(l.lmax, l.sum + r.lmax);
                t.rmax = max(r.rmax, r.sum + l.rmax);
                t.sum = l.sum + r.sum;
                t.ans = max(max(l.ans, r.ans), l.rmax + r.lmax);
                tt.pb(t);
            }
            for(int k = 0; k < solve[i - 1][j].size(); k++) {
                node t, l, r;
                r = solve[i - 1][j][k];
                l = solve[i - 1][j + 1][k];
                t.lmax = max(l.lmax, l.sum + r.lmax);
                t.rmax = max(r.rmax, r.sum + l.rmax);
                t.sum = l.sum + r.sum;
                t.ans = max(max(l.ans, r.ans), l.rmax + r.lmax);
                tt.pb(t);
            }
            solve[i].pb(tt);
        }
    }
    int a = 0;
    int q;
    cin >> q;
    int kk;
    while(q--) {
        cin >> kk;
        a ^= (1 << kk);
        cout << solve[k][0][a].ans << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) sol(i);
    return 0;
}