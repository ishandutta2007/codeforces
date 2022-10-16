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
int sps1[25][300005], sps2[25][300005];
int min1(int l, int r) {
    if(r % 2 != l % 2) r--;
    if(l > r) return INT_MAX;
    int range = r - l + 2;
    int k = 0;
    while((1 << (k + 2)) <= range) k++;
    int kk = min(sps1[k][l], sps1[k][r - (1 << (k + 1)) + 2]);
    //cerr << "one:" << l << ' ' << r << ' ' << k << ' ' << kk << '\n';
    return kk;
}
int min2(int l, int r) {
    if(r % 2 != l % 2) r--;
    int range = r - l + 1;
    int k = 0;
    while((1 << (k + 2)) <= range) k++;
    int kk = min(sps2[k][l], sps2[k][r - (1 << (k + 1)) + 2]);
    //cerr << "two:" << l << ' ' << r << ' ' << k << ' ' << kk << '\n';
    return kk;
}
unordered_map<int, vector<int>> rev1, rev2;
int count(int arrk, int l, int r) {
    //cerr << l << ' ' << r << '\n';
    //for(auto x: arr) cerr << x << ' '; cerr << '\n';
    if(rev1[arrk].size() == 0) return 0;
    if(r < l) return 0;
    int le, ri;
    le = 0, ri = rev1[arrk].size() - 1;
    if(r < rev1[arrk][le]) return 0;
    if(l > rev1[arrk][ri]) return 0;
    while(le < ri) {
        int mm = (le + ri) / 2;
        if(rev1[arrk][mm] < l) le = mm + 1;
        else ri = mm;
    }
    int one = le;
    le = 0, ri = rev1[arrk].size() - 1;
    while(le < ri) {
        int mm = (le + ri + 1) / 2;
        if(rev1[arrk][mm] <= r) le = mm;
        else ri = mm - 1;
    }
    return ri - one + 1;
}
void solve(int TC) {
    rev1.clear();
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int ps1[n + 5], ps2[n + 5];
    ps1[0] = ps2[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            ps1[i] = ps1[i - 1] + arr[i];
            ps2[i] = ps2[i - 1] - arr[i];
        }
        else {
            ps1[i] = ps1[i - 1] - arr[i];
            ps2[i] = ps2[i - 1] + arr[i];
        }
        sps1[0][i] = ps1[i];
        rev1[ps1[i]].pb(i);
        sps2[0][i] = ps2[i];
        rev2[ps2[i]].pb(i);
    } 
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= n; j++) {
            sps1[i][j] = min(sps1[i - 1][j], sps1[i - 1][min(n, j + (1 << (i)))]);
            sps2[i][j] = min(sps2[i - 1][j], sps2[i - 1][min(n, j + (1 << (i)))]);
        }
    }
    //for(int i = 0; i <= n; i++) cerr << ps1[i] << ' '; cout << '\n';
    //for(int i = 0; i <= n; i++) cerr << ps2[i] << ' '; cout << '\n';
    //cerr << min1(0, 1) << ' ' << min1(0, 2) << ' ' << min1(0, 3) << ' ' << min1(0, 4) << '\n';
    //cerr << min2(0, 1) << ' ' << min2(0, 2) << ' ' << min2(0, 3) << ' ' << min2(0, 4) << '\n';
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l = i + 1, r = n;
        while(l < r) {
            int m = (l + r + 1) / 2;
            //cerr << l << ' ' << r << ' ' << m << ' ' << i << '\n';
            bool can = true;
            if(i % 2 == 0) {
                if(min1(i + 1, m) < ps1[i]) can = false;
                if(min2(i + 2, m) < ps2[i]) can = false;
            }
            else {
                if(min1(i + 2, m) < ps1[i]) can = false;
                if(min2(i + 1, m) < ps2[i]) can = false;
            }
            if(!can) r = m - 1;
            else l = m;
        }//return;
        ans += count(ps1[i], i + 1, l);
    }  
    cout << ans << '\n'; return;
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