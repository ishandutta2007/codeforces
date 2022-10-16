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
int dsu[100005];
int f(int x) {
    if(dsu[x] == x) return x;
    return dsu[x] = f(dsu[x]);
}
void merge(int a, int b) {
    dsu[f(a)] = f(b);
}
void solve(int TC) {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) dsu[i] = i;
    int ans[n + 5];
    bool done[n + 5];
    for(int i = 0; i <= n; i++) done[i] = false;
    vector<pair<int, int>> nds;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        nds.pb(mp(t, i));
    }
    sort(nds.begin(), nds.end());
    reverse(nds.begin(), nds.end());
    int left = n;
    for(auto x: nds) {
        if(!done[x.se]) {
            for(int i = 0; i < min(left, x.fi); i++) {
                left--;
                cout << "? " << x.se << endl;
                fflush(stdout);
                int tt;
                cin >> tt;
                merge(tt, x.se);
                done[x.se] = true;
                if(done[tt]) break;
                done[tt] = true;
            }
            // left -= min(left, x.fi);
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << f(i) << ' ';
    cout << endl;
    fflush(stdout);
}
signed main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}