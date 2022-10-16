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
vector<int> conn[300005];
int w[300005];
int s[300005];
int n;
void dfs(int now, int fa) {
    vector<int> ha;
    w[now] = 1;

    for(auto x: conn[now]) {
        if(x != fa) {
            dfs(x, now);
            ha.pb(x);
            w[now] += w[x];
        }
    }
    if(ha.size() == 0) {
        s[now] = 0;
    }
    else if(ha.size() == 1) {
        s[now] = w[ha[0]] - 1;
    }
    else {
        s[now] = max(s[ha[0]] + w[ha[1]], s[ha[1]] + w[ha[0]]) - 1;
    }
}
void solve(int TC) {
    cin >> n;
    for(int i = 1; i <= n; i++) conn[i].clear();
    int a, b;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        conn[a].pb(b);
        conn[b].pb(a);
    }
    // ans = 0;
    dfs(1, 1);
    cout << s[1] << '\n';
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