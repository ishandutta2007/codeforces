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
vector<int> fib;
vector<int> sum;
void solve(int TC) {
    int n;
    cin >> n;
    int sm = 0;
    int t;
    priority_queue<pair<int, int>> oof;
    for(int i = 0; i < n; i++) {
        cin >> t;
        sm += t;
        oof.push(mp(t, -1));
    }
    if(n == 1) {
        if(sm == 1) {
            cout << "YES\n";
        }
        else cout << "NO\n";
        return;
    }
    int i = 0;
    for(auto x: sum) {
        if(x == sm) break;
        i++;
    }
    if(i == sum.size()) {
        cout << "NO\n";
        return;
    }
    for(; i >= 0; i--) {
        auto t = oof.top();
        oof.pop();
        if(t.se == i + 1) {
            auto tt = oof.top();
            oof.pop();
            if(tt.fi < fib[i]) {
                cout << "NO\n";
                return;
            }
            tt.fi -= fib[i];
            tt.se = i;
            oof.push(t);
            oof.push(tt);
        }
        else {  
            if(t.fi < fib[i]) {
                cout << "NO\n";
                return;
            }
            t.fi -= fib[i];
            t.se = i;
            oof.push(t);
        }
    }
    cout << "YES\n";
} 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    fib.pb(1);
    fib.pb(1);
    sum.pb(1);
    sum.pb(2);
    int t = 2;
    while(t <= 100000000000) {
        fib.pb(t);
        sum.pb(sum[sum.size() - 1] + t);
        t += fib[fib.size() - 2];
    }
    // cout << fib.size() << '\n';
    t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}