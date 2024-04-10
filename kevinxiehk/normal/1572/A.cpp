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
void solve(int TC) {
    int n;
    cin >> n;
    int ans[n + 5];
    vector<int> give[n + 5];
    vector<int> need[n + 5];
    int cnt[n + 5];
    int t, tt;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        cnt[i] = t;
        ans[i] = 1;
        while(t--) {
            cin >> tt;
            need[i].pb(tt);
            give[tt].pb(i);
        }
    }
    queue<int> can;
    for(int i = 1; i <= n; i++) if(cnt[i] == 0) can.push(i);
    while(!can.empty()) {
        int now = can.front();
        can.pop();
        for(auto x: give[now]) {
            cnt[x]--;
            if(x < now) ans[x] = max(ans[x], ans[now] + 1);
            else ans[x] = max(ans[x], ans[now]);
            if(cnt[x] == 0) can.push(x);
        }
    }
    int anss = 0;
    for(int i = 1; i <= n; i++) {
        anss = max(anss, ans[i]);
        if(cnt[i] > 0) {
            cout << "-1\n";
            return;
        }
    }
    cout << anss << '\n';
    return;
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