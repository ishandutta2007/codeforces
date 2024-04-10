#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int a;
pair<int, int> part(vector<int> &t) {
    pair<int, int> an = mp(t[0], t[0]);
    a = 1;
    pair<int, int> now = mp(t[0], 1);
    for(int i = 1; i < t.size(); i++) {
        if(now.se + 2 - t[i] + t[i - 1] > 1) {
            now.se = now.se + 2 - t[i] + t[i - 1];
        }
        else {
            now = mp(t[i], 1);
        }
        if(now.se > a) {
            a = now.se;
            an = mp(now.fi, t[i]);
        }
    }
    return an;
}
void solve(int TC) {
    int n; cin >> n;
    map<int, vector<int>> stuff;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        stuff[t].pb(i + 1);
    }
    int ansl, ansr, aans = -inf, ansa;
    for(auto &x: stuff) {
        a = -inf;
        pair<int, int> t = part(x.se);
        if(a > aans) {
            aans = a;
            ansl = t.fi;
            ansr = t.se;
            ansa = x.fi;
        }
    }
    cout << ansa << ' ' << ansl << ' ' << ansr << '\n';
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