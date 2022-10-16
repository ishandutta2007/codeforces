#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, l, r, t;
    cin >> n >> l >> r;
    int ll = l, rr = r;
    map<int, int> cl, rt;
    for(int i = 0; i < ll; i++) {
        cin >> t;
        cl[t]++;
        //left.pb(t);
    }
    for(int i = 0; i < rr; i++) {
        cin >> t;
        if(cl[t] > 0) {
            cl[t]--;
            n -= 2;
            l--;
            r--;
        }
        else rt[t]++;
    }
    int cnt = 0;
    int tt = 0;
    if(l > r) for(auto x: cl) {
        t = x.se / 2;
        tt += t;
    }
    else for(auto x: rt) {
        t = x.se / 2;
        tt += t;
    }
    cnt += max(0LL, abs(l - r) / 2 - tt);
    cnt += n / 2;
    cout << cnt << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    return 0;
}