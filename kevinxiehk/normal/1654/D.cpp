#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define iint long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
iint bm(iint a, iint b, iint mod) {
    if(b == 0) return 1; 
    iint t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}

vector<pair<int, pair<int, int>>> conn[200005];
int mod = 998244353;
iint ans;

unordered_map<int, int> mxneed;
unordered_map<int, int> currneed;

vector<int> ff[200005][2];

void pf(int a, int x, int y) {
    ff[x][y].clear();
    for(int i = 2; i * i <= a; i++) {
        while(a % i == 0) {
            a /= i;
            ff[x][y].pb(i);
        }
    }   
    if(a >= 1) {
        ff[x][y].pb(a);
    }
    return;
}

void dfs1(int now, int f) {
    for(auto x: conn[now]) {
        if(x.fi == f) continue;
        pf(x.se.se, now, 0);
        for(auto xx: ff[now][0]) currneed[xx]--;
        pf(x.se.fi, now, 1);
        for(auto xx: ff[now][1]) {
            currneed[xx]++;
            if(currneed[xx] > 0) {
                mxneed[xx] = max(mxneed[xx], currneed[xx]);
            }
        }
        dfs1(x.fi, now);
        // pf(x.se.se);
        for(auto xx: ff[now][0]) currneed[xx]++;
        // pf(x.se.fi);
        for(auto xx: ff[now][1]) currneed[xx]--;
    }
}
void dfs2(int now, int f, iint k) {
    ans += k;
    for(auto x: conn[now]) {
        if(x.fi == f) continue;
        dfs2(x.fi, now, k * x.se.se % mod * inv(x.se.fi, mod) % mod);
    }
    return;
}
void solve(int TC) {
    mxneed.clear();
    currneed.clear();
    int n;
    cin >> n;
    int t, tt, ttt, tttt;
    for(int i = 0; i <= n; i++) {
        conn[i].clear();
    }
    ans = 0;
    for(int i = 1; i < n; i++) {
        cin >> t >> tt >> ttt >> tttt;
        conn[t].pb(mp(tt, mp(ttt, tttt)));
        conn[tt].pb(mp(t, mp(tttt, ttt)));
    }
    dfs1(1, 1);
    int a = 1;
    for(auto x: mxneed) {
        a = a * bm(x.fi, x.se, mod) % mod;
    }
    dfs2(1, 1, a);
    cout << ans % mod << '\n';
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