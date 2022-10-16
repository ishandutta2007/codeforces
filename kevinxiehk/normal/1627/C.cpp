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
    vector<pair<int, int>> conn[n + 5];
    int t, tt;
    for(int i = 1; i < n; i++) {
        cin >> t >> tt;
        conn[t].pb(mp(tt, i - 1));
        conn[tt].pb(mp(t, i - 1));
    } 
    int ans[n + 5];
    int id = -1;
    for(int i = 1; i <= n; i++) {
        if(conn[i].size() > 2) {
            cout << "-1\n";
            return;
        }
        if(conn[i].size() == 1) id = i;
    }
    int now = id, fa = id;
    stack<pair<int, int>> dfs;
    dfs.push(mp(now, fa));
    int curr = 2;
    while(!dfs.empty()) {
        pair<int, int> ttt = dfs.top();
        dfs.pop();
        ans[ttt.se] = curr;
        curr ^= 1;
        for(auto x: conn[ttt.fi]) {
            if(x.fi != fa) {
                dfs.push(x);
                fa = ttt.fi;
                break;
            }
        }
    }
    for(int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
    cout << '\n';
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