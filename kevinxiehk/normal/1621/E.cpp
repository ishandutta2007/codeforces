#pragma GCC optimize("Ofast")
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
int seg[400005];
int lazy[400005];
unordered_map<int, bool> vi;
void upd(int val, int l, int r, int ll, int rr, int id) {
    vi[id] = true;
    if(ll > r || rr < l) return;
    else if(ll == rr) {
        seg[id] += val;
        return;
    }
    else if(ll >= l && rr <= r) {
        seg[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (ll + rr) / 2;
    if(lazy[id] != 0) {
        seg[id * 2] += lazy[id];
        lazy[id * 2] += lazy[id];
        vi[id * 2] = true;
        seg[id * 2 + 1] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        vi[id * 2 + 1] = true;
        lazy[id] = 0;
    }
    upd(val, l, r, ll, mid, id * 2);
    upd(val, l, r, mid + 1, rr, id * 2 + 1);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
bool can() {
    // cout << seg[1] << '\n';
    return seg[1] >= 0;
}
void solve(int TC) {
    int n, m, t, tt;
    cin >> n >> m;
    vector<int> teach;
    vector<int> stu[m + 5];
    int sum[m + 5];
    int cnt[m + 5];
    for(int i = 0; i < n; i++) {
        cin >> t;
        teach.pb(t);
        upd(1, 0, t, 0, 100000, 1);
    }
    for(int i = 0; i < m; i++) {
        sum[i] = 0;
        cin >> cnt[i];
        for(int j = 0; j < cnt[i]; j++) {
            cin >> tt;
            sum[i] += tt;
            stu[i].pb(tt);
        }
        int avg = (sum[i] + cnt[i] - 1) / cnt[i];
        upd(-1, 0, avg, 0, 100000, 1);
    }
    string ans = "";
    for(int i = 0; i < m; i++) {
        int avg = (sum[i] + cnt[i] - 1) / cnt[i];
        upd(1, 0, avg, 0, 100000, 1);
        for(auto x: stu[i]) {
            int newavg = (sum[i] - x + cnt[i] - 2) / (cnt[i] - 1);
            // cerr << newavg << '\n';
            upd(-1, 0, newavg, 0, 100000, 1);
            if(can()) ans += "1";
            else ans += "0";
            upd(1, 0, newavg, 0, 100000, 1);
        }
        upd(-1, 0, avg, 0, 100000, 1);
    }
    cout << ans << '\n';
    // REMEMBER TO CLEAR
    // for(auto x: teach) {
    //     upd(-1, 0, x, 0, 100000, 1);
    // }
    // for(int i = 0; i < m; i++) {
    //     int avg = (sum[i] + cnt[i] - 1) / cnt[i];
    //     upd(1, 0, avg, 0, 100000, 1);
    // }
    int summ = 0;
    for(auto x: vi) seg[x.fi] = lazy[x.fi] = 0, summ++;
    vi.clear();
    // cerr << summ << '\n';
    // for(int i = 0; i <= 400000; i++) if(seg[i] != 0) cerr << i << ' ' << seg[i] << '\n';
    // cout << summ << '\n';
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