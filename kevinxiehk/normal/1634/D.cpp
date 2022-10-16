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
struct grp{
    int a, b, c;
};
int ask(grp x) {
    cout << "? " << x.a << ' ' << x.b << ' ' << x.c << endl;
    int ans;
    cin >> ans;
    return ans;
}
bool cmp(pair<int, grp> a, pair<int, grp> b) {
    return a.fi < b.fi;
}
void solve(int TC) {
    int n;
    cin >> n;
    vector<pair<int, grp>> store;
    grp t;
    t.a = 1; t.b = 2;
    for(int i = 3; i <= n; i++) {
        t.c = i;
        store.pb(mp(ask(t), t));
    }
    sort(store.begin(), store.end(), cmp);
    reverse(store.begin(), store.end());
    t.a = store[0].se.c;
    t.b = store[1].se.c;
    for(int i = 1; i <= n; i++) {
        if(i == t.a || i == t.b) continue;
        t.c = i;
        store.pb(mp(ask(t), t));
    }
    sort(store.begin(), store.end(), cmp);
    reverse(store.begin(), store.end());
    grp hm = store[0].se;
    int i = 1;
    while(i == hm.a || i == hm.b || i == hm.c) i++;
    grp tt = hm;
    tt.a = i;
    bool fir = (ask(tt) == store[0].fi);
    tt = hm;
    tt.b = i;
    bool sec = (ask(tt) == store[0].fi);
    if(fir) {
        cout << "! " << hm.b << ' ' << hm.c << endl;
    }
    else if(sec) {
        cout << "! " << hm.a << ' ' << hm.c << endl;
    }
    else {
        cout << "! " << hm.a << ' ' << hm.b << endl;
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