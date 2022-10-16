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
pair<int, int> dsu[200005];
pair<pair<int, int>, pair<int, int>> arr[200005];
int cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    if(a.fi.se == b.fi.se) return a.fi.fi < b.fi.fi;
    return a.fi.se < b.fi.se;
}
int f(int x) {
    if(x == dsu[x].fi) return x;
    return dsu[x].fi = f(dsu[x].fi);
}
void merge(int a, int b) {
    if(f(a) == f(b)) return;
    int k = min(dsu[f(a)].se, dsu[f(b)].se);
    dsu[f(a)] = mp(f(b), k);
    dsu[f(b)].se = k;
}
void solve(int TC) {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].fi.fi >> arr[i].fi.se >> arr[i].se.fi;
        arr[i].se.se = i;
        dsu[i] = mp(i, arr[i].se.fi);
    }
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++) {
        if(arr[i].fi.fi == arr[i + 1].fi.fi && arr[i + 1].fi.se - arr[i].fi.se <= k) merge(arr[i].se.se, arr[i + 1].se.se);
    }
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n - 1; i++) {
        if(arr[i].fi.se == arr[i + 1].fi.se && arr[i + 1].fi.fi - arr[i].fi.fi <= k) merge(arr[i].se.se, arr[i + 1].se.se);
    }
    set<pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        int aa = f(i);
        st.insert(mp(dsu[aa].se, aa));
    }
    vector<pair<int, int>> hm;
    for(auto x: st) hm.pb(x);
    int nn = st.size();
    int ans = nn - 1;
    for(int i = 0; i < nn; i++) {
        ans = min(ans, max(hm[i].fi, nn - i - 2));
    }
    cout << ans << '\n';
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