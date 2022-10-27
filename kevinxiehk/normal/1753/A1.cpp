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
    int arr[n + 5];
    int pf[n + 5];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 2; i <= n; i += 2) {
        arr[i] *= -1;
    }
    int sum = 0;
    pf[0] = 0;
    for(int i = 1; i <= n; i++) pf[i] = pf[i - 1] + arr[i];
    sum = pf[n];
    if(sum % 2 != 0) {
        cout << "-1\n";
        return;
    }
    if(sum == 0) {
        cout << "1\n1 " << n << '\n';
        return;
    }
    vector<pair<int, int>> ans;
    if(sum % 4 == 0) {
        int md;
        for(int i = 1; i <= n; i++) {
            if(abs(pf[i]) % 4 == 2) {
                md = i;
                break;
            }
        }
        for(int i = 1; i <= md; i++) {
            if(pf[i] == pf[md] / 2) {
                ans.pb(mp(1, i));
                ans.pb(mp(i + 1, md));
                break;
            }
        }
        for(int i = md + 1; i <= n; i++) {
            if(pf[i] - pf[md] == (sum - pf[md]) / 2) {
                ans.pb(mp(md + 1, i));
                ans.pb(mp(i + 1, n));
                break;
            }
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(pf[i] == sum / 2) {
                ans.pb(mp(1, i));
                ans.pb(mp(i + 1, n));
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x.fi << ' ' << x.se << '\n';
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