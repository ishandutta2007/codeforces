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
    int n, k;
    cin >> n >> k;
    int arr[n + 5];
    vector<pair<int, int>> freq;
    map<int, int> p;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        p[arr[i]]++;
    }
    for(auto x: p) freq.pb(mp(x.se, x.fi));
    sort(freq.begin(), freq.end());
    int tm = 0;
    int diff = freq.size();
    int nn = freq.size();
    int pt = 0;
    int lef = 0;
    map<int, int> used;

    for(int i = 0; i < n; i++) {
        if(tm > k) break;
        if(p[i] > 0) {
            lef += used[i];
            if(used[i] < p[i]) diff--;
        }
        else {
            tm++;
            lef++;
        }
        if(tm > k) break;
        while(lef > 0) {
            while(pt < nn && freq[pt].se <= i) pt++;
            if(pt == nn) break;
            int kk = min(freq[pt].fi - used[freq[pt].se], lef);
            lef -= kk;
            used[freq[pt].se] += kk;
            if(freq[pt].fi == used[freq[pt].se]) {
                pt++;
                diff--;
            }
            // if(pt == nn) break;
        }
        // cout << i << ' ' << diff << '\n';
            // if(pt == nn) break;
    }
    cout << diff << '\n';
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