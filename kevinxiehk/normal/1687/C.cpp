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
int fen[200005];
int ar[200005];
int n;
void add(int id) {
    ar[id] = 1;
    for(; id <= n + 1; id += id & -id) fen[id]++;
}
int sum(int id) {
    id = min(id, n + 1);
    int ans = 0;
    for(; id > 0; id -= id & -id) ans += fen[id];
    return ans;
}
int nxt(int l) {
    for(int i = (1 << 20); i > 0; i /= 2) {
        if(sum(l + i) == sum(l) + i) l += i;
    } 
    return l + 1;
}
void solve(int TC) {
    int m;
    cin >> n >> m;
    for(int i = 0; i <= n + 3; i++) fen[i] = ar[i] = 0;
    int a[n + 5], b[n + 5];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    pair<int, int> mv[m + 5];
    for(int i = 0; i < m; i++) cin >> mv[i].fi >> mv[i].se;
    for(int i = 0; i < m; i++) mv[i].se++;
    sort(mv, mv + m);

    vector<int> other[n + 5];
    for(int i = 0; i < m; i++) {
        other[mv[i].fi].pb(mv[i].se);
        other[mv[i].se].pb(mv[i].fi);
    }
    queue<pair<int, int>> can;
    int arr[n + 5];
    arr[0] = 0;
    add(1);
    // set<pair<int, int>> ye;
    for(int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + a[i] - b[i];
        if(arr[i] == 0) add(i + 1);
        // cout << arr[i] << '\n';
    }
    if(arr[n] != 0) {
        cout << "NO\n";
        return;
    }

    // int pt = 0;
    // while(pt < n && arr[pt + 1] == 0) pt++;
    for(int i = 0; i < m; i++) {
        if(ar[mv[i].fi] + ar[mv[i].se] == 2) {
            can.push(mv[i]);
        }
        // cout << i << ' ' << pt << '\n';
    }

    while(!can.empty()) {
        pair<int, int> now = can.front();
        if(now.fi > now.se) swap(now.fi, now.se);
        can.pop();
        // if(sum(now.se + 1) == sum(now.fi) + n) continue;
        int nx = nxt(now.fi);
        while(nx < now.se) {
            add(nx);
            for(auto x: other[nx]) {
                if(ar[x] == 1) can.push(mp(x, nx));
            }
            nx = nxt(nx);
        }
    }

    if(sum(n + 1) == n + 1) cout << "YES\n";
    else cout << "NO\n";
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