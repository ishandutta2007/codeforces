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
int query(vector<int> arr) {
    cout << "? ";
    for(auto x: arr) cout << x << ' ';
    cout << endl;
    int n;
    cin >> n;
    return n;
}
void solve(int TC) {
    int n;
    cin >> n;
    int nx[n + 5], la[n + 5];
    for(int i = 0; i < n; i++) nx[i] = la[i] = -1;
    vector<int> ask(n);
    vector<int> ask2(n);
    for(int i = 0; i < n; i++) ask[i] = 1;
    for(int i = 0; i < n; i++) ask2[i] = n;
    for(int r = n - 1; r > 0; r--) {
        ask[r] = 2;
        int t = query(ask);
        if(t != 0 && t <= r) {
            t--;
            la[t] = r;
            nx[r] = t;
        }
        ask2[r] = n - 1;
        t = query(ask2);
        if(t != 0 && t <= r) {
            t--;
            nx[t] = r;
            la[r] = t;
        }
        if(nx[r] != -1) ask2[r] = 1;
        else ask2[r] = n;
        if(la[r] != -1) ask[r] = n;
        else ask[r] = 1;
    }
    int ans[n + 5];
    int now;
    for(int i = 0; i < n; i++) if(la[i] == -1) now = i;
    for(int i = 1; i <= n; i++) {
        ans[now] = i;
        now = nx[now];
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}
signed main(){
    //ios_base::sync_with_stdio(false); 
    //cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}