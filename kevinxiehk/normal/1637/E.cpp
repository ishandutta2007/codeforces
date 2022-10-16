#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ll long long
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
inline ll encode(ll a, int b) {
    return ((a << 30) | b);
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.fi + a.se > b.fi + b.se;
}
clock_t ti=clock();
int tn = 0;
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    tn += n;
    map<int, int> freq;
    unordered_map<int, vector<int>> rfreq;
    int t;
    while(n--) {
        cin >> t;
        freq[t]++;
    }
    unordered_map<ll, bool> bad;
    bad.reserve(m * 2);
    int tt;
    for(int i = 0; i < m; i++) {
        cin >> t >> tt;
        bad[encode(t, tt)] = bad[encode(tt, t)] = true;
    }
    vector<pair<int, int>> arr;
    for(auto &x: freq) {
        rfreq[x.se].pb(x.fi);
        arr.pb(mp(x.fi, x.se));
    }
    for(auto &x : rfreq) {
        reverse(x.se.begin(), x.se.end());
    }
    ll aa = 0;
    sort(arr.begin(), arr.end(), cmp);
    for(auto &x: arr) {
        for(auto &y: rfreq) {
            for(auto &z: y.se) {
                if(z == x.fi) continue;
                if(aa > (ll)(x.fi + z) * (ll)(x.se + y.fi)) break;
                if(!bad[encode(x.fi, z)]) {
                    aa = max(aa, (ll)(x.fi + z) * (ll)(x.se + y.fi));
                    break;
                }
            }
        }
    }
    cout << aa << '\n';
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