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
vector<pair<vector<int>, int>> stuff;
bool fill(int l, int r) {
    for(auto &x: stuff) {
        bool have = false;
        for(auto xx: x.fi) {
            if(xx <= r && xx >= l) {
                have = true;
                x.se = xx;
            }
        }
        if(!have) return false;
    }
    return true;
}
bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
    return a.se < b.se;
}
int arr[405];
int n = 400;
vector<int> ans;
int vi[405];
void construct(int a) {
    // cout << a << '\n';
    vi[a] = true;
    int out = 0;
    for(auto x: stuff[a].fi) {
        if(out) ans.pb(x);
        if(out) {
            for(int i = 0; i < stuff.size(); i++) if(stuff[i].se == x + 1 && !vi[i]) construct(i); 
        }
        if(x == stuff[a].se) out = 1;
    }
    for(auto x: stuff[a].fi) {
        if(out) ans.pb(x);
        if(out) {
            for(int i = 0; i < stuff.size(); i++) if(stuff[i].se == x + 1 && !vi[i]) construct(i); 
        }
        if(x == stuff[a].se) out = 0;
    }
}
void solve(int TC) {
    stuff.clear();
    ans.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        vi[i - 1] = false;
    }

    // for(int i = 1; i <= n; i++) {
    //     arr[i] = i;
    // }
    // random_shuffle(arr + 1, arr + 1 + n);

    vector<int> tmp;
    bool vi[n + 5];
    for(int i = 0; i <= n; i++) vi[i] = false;
    for(int i = 1; i <= n; i++) {
        if(!vi[i]) {
            int now = i;
            int mi = inf;
            do{
                vi[now] = true;
                tmp.pb(now);
                mi = min(now, mi);
                now = arr[now];
            } while(now != i);
            reverse(tmp.begin(), tmp.end());
            stuff.pb(mp(tmp, mi));
            tmp.clear();
        }
    }
    for(int i = 0; i < stuff.size(); i++) if(stuff[i].se == 1) construct(i);
    // int bes = inf;
    // int bsl, bsr;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = i; j <= n; j++) {
    //         if(j - i + 1 >= bes) continue;
    //         if(fill(i, j)) {
    //             bes = j - i + 1;
    //             bsl = i; bsr = j;
    //         }
    //     }
    // }
    // fill(bsl, bsr);
    // sort(stuff.begin(), stuff.end(), cmp);
    // for(auto x: stuff) {
    //     int out = 0;
    //     for(auto xx: x.fi) {
    //         if(out == 1) ans.pb(xx);
    //         if(xx == x.se) out ^= 1;
    //     }
    //     for(auto xx: x.fi) {
    //         if(out == 1) ans.pb(xx);
    //         if(xx == x.se) out ^= 1;
    //     }
    // }

    for(auto x: ans) cout << x << ' '; cout << '\n';

    return;

    // sort(ans.begin(), ans.end());
    // int mi = inf;
    // do {
    //     int cost = 0;
    //     for(int i = 1; i <= n; i++) {
    //         if(i != n) cost += abs(ans[i - 1] - arr[ans[i]]);
    //         else cost += abs(ans[i - 1] - arr[ans[0]]);
    //     }
    //     mi = min(mi, cost);
    // } while(next_permutation(ans.begin(), ans.end()));
    
    // if(mi != (bes - 1) * 2) {
    //     cout << mi << ' ' << (bes - 1) * 2 << '\n';
    // }

    // do {
    //     int cost = 0;
    //     for(int i = 1; i <= n; i++) {
    //         if(i != n) cost += abs(ans[i - 1] - arr[ans[i]]);
    //         else cost += abs(ans[i - 1] - arr[ans[0]]);
    //     }
    //     // mi = min(mi, cost);
    //     if(cost == mi) {
    //         for(auto x: ans) cout << x << ' '; cout << '\n';
    //     }
    // } while(next_permutation(ans.begin(), ans.end()));
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    srand(time(NULL));
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}