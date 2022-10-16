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
vector<int> conn[200005];
bool vi[200005];
bool can;
int dfs(int x) {
    if(vi[x]) return 0;
    vi[x] = true;
    if(conn[x].size() != 2) can = false;
    for(auto xx: conn[x]) {
        if(!vi[xx]) return dfs(xx) + 1;
    }
    return 1;
}
void solve(int TC) {
    int n;
    cin >> n;
    can = true;
    for(int i = 1; i <= n; i++) {
        conn[i].clear();
        vi[i] = true;
    }
    int a, b;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a == b) can = false;
        vi[a] = vi[b] = false;
        conn[a].pb(b);
        conn[b].pb(a);
    }
    for(int i = 1; i <= n; i++) {
        if(!vi[i]) {
            if(dfs(i) % 2) can = false;
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     if(!vi[i]) {
    //         cout << "YES\n";
    //         return;
    //     }
    // }
    if(can) cout << "YES\n";
    else cout << "NO\n";
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