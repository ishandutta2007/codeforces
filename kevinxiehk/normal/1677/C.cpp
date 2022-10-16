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
vector<int> conn[100005];
bool vi[100005];
bool cmp(int a, int b) {
    if(a % 2 != b % 2) return a % 2 == 0;
    return a > b;
}
vector<int> len;
int dfs(int now) {
    int cn = 0;
    vi[now] = true;
    for(auto x: conn[now]) {
        if(!vi[x]) cn = max(cn, dfs(x));
    }
    return cn + 1;
}
void solve(int TC) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        conn[i].clear();
        vi[i] = false;
    }
    int a[n + 5], b[n + 5];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        conn[a[i]].pb(b[i]);
        conn[b[i]].pb(a[i]);
    }
    len.clear();
    for(int i = 1; i <= n; i++) if(!vi[i]) len.pb((dfs(i)) / 2 * 2);
    sort(len.begin(), len.end(), cmp);
    vector<int> ar;
    for(int i = 1; i <= n / 2; i++) {
        ar.pb(i);
        ar.pb(n + 1 - i);
    }
    if(n % 2 == 1) ar.pb(n / 2 + 1);
    int ans = 0;
    vector<int> wtf;
    wtf.pb(0);
    wtf.pb(0);
    int ls = 0;
    for(int i = 2; i <= n; i += 2) {
        wtf.pb(ls + i); ls += i;
        wtf.pb(ls + i); ls += i;
    }
    // int st = 0;
    int width = n;
    for(auto x: len) {
        // for(int i = 1; i < x; i++) {
        //     ans += abs(ar[i + st] - ar[i + st - 1]);
        // }
        // ans += abs(ar[st] - ar[st + x - 1]);
        // st += x;
        width -= x;
        ans += x / 2 * 2 * width;
        ans += wtf[x];
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