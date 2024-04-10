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
    int ar[n + 5];
    vector<int> fr, wa;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans += t;
        if(ar[i] == 0) fr.pb(t);
        else wa.pb(t);
    }
    sort(fr.begin(), fr.end());
    sort(wa.begin(), wa.end());
    reverse(fr.begin(), fr.end());
    reverse(wa.begin(), wa.end());
    int a1 = 0, a2 = 0;
    for(int i = 0; i < min(fr.size(), wa.size()); i++) {
        a1 += wa[i];
    }
    for(int i = 0; i < min((int)(fr.size()) - 1, (int)(wa.size())); i++) {
        a1 += fr[i];
    }
    for(int i = 0; i < min((int)(fr.size()), (int)(wa.size()) - 1); i++) {
        a2 += wa[i];
    }
    for(int i = 0; i < min(fr.size(), wa.size()); i++) {
        a2 += fr[i];
    }
    cout << ans + max(a1, a2) << '\n';
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