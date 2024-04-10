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
pair<int, int> pp[100005];
    int a[100005];
string ans = "";
    int n, q;
int tr(int k) {
    for(int i = 0; i < n; i++) ans[i] = '0';
    int qq = q - k;
    for(int i = n - 1; i >= 0; i--) {
        if(qq >= a[i]) ans[i] = '1';
        else if(k > 0) {
            ans[i] = '1';
            qq++;
            k--;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += ans[i] - '0';
    return cnt;
}
void solve(int TC) {
    ans = "";
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        pp[i] = mp(a[i], i);
        ans += '0';
    }
    sort(pp, pp + n);
    int l = 0, r = q;
    // for(int i = 0; i <= n; i++) cout << tr(i) << ' ';
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(tr(m - 1) > tr(m)) r = m - 1;
        else l = m;
    }
    tr(l);
    // cout << l << '\n';
    // int m = l;
    // for(int i = 0; i < n; i++) ans[i] = '0';
    // for(int i = 0; i < m; i++) ans[pp[i].se] = '1';
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