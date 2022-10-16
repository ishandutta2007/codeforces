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
    int n, k;
    cin >> n >> k;
    pair<int, int> arr[n + 5];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr + 1, arr + 1 + n);
    vector<pair<int, int>> edges;
    if(arr[1].fi != 0) {
        cout << "-1\n";
        return;
    }
    stack<pair<int, int>> dk[n + 5];
    dk[0].push(mp(arr[1].se, k));
    for(int i = 2; i <= n; i++) {
        if(arr[i].fi == 0 || dk[arr[i].fi - 1].empty()) {
            cout << "-1\n";
            return;
        }
        auto now = dk[arr[i].fi - 1].top();
        dk[arr[i].fi - 1].pop();
        now.se--;
        if(now.se > 0) dk[arr[i].fi - 1].push(now);
        edges.pb(mp(now.fi, arr[i].se));
        if(k != 1) dk[arr[i].fi].push(mp(arr[i].se, k - 1));
    }
    cout << edges.size() << '\n';
    for(auto x: edges) cout << x.fi << ' ' << x.se << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}