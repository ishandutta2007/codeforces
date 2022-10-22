#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << rl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << rl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << rl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << rl;
//#define Ptest(x)            return cout << x, 0;
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calc    
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAX_M = 200010;
// code
#define int long long

int n, m, L, s, t;
int cnt = -1;
vector<pair<pii, pii>> adj[1010];
int dist[1010];

int dijk(int pc, int val){
    for (int i = 0; i <= n; i++) dist[i] = 1e18;
    dist[s] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    
    while (pq.size()){
        int d = pq.top().F, u = pq.top().S;
        pq.pop();
        for (auto ed:adj[u]){
            int v = ed.F.F, w = ed.F.S;
            if (ed.S.F >= 0){
                if (ed.S.F < pc)
                    w = 1;
                else if (ed.S.F == pc)
                    w = val;
                else
                    w = 1e18;
            }
            if (dist[u] == d){
                if (dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    //cout << pc << ' ' << val << ' ' << dist[t] << endl;
    return dist[t];
}

void print(int pc, int val){
    cout << "YES\n";
    vector<pair<pii, int>> edge(m);
    for (int u = 0; u < n; u++){
        for (auto ed:adj[u]){
            if (ed.S.S == -1)
                continue;
            int v = ed.F.F, w = ed.F.S;
            if (ed.S.F >= 0){
                if (ed.S.F < pc)
                    w = 1;
                else if (ed.S.F == pc)
                    w = val;
                else
                    w = 2e12;
            }
            edge[ed.S.S] = {{u, v}, w};
        }
    }
    for (auto ed:edge){
        cout << ed.F.F << ' ' << ed.F.S << ' ' << ed.S << endl;
    }
}

void Solve() {
    cin >> n >> m >> L >> s >> t;
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        int idx = -1;
        if (!w)
            idx = ++cnt;
        //cout << idx << ' ';
        adj[u].pb({{v, w}, {idx, i}});
        adj[v].pb({{u, w}, {idx, -1}});
    }
    int x = dijk(cnt, 1), y = dijk(-1, 0);
    if (x > L || y < L){
        cout << "NO\n";
        return;
    }else{
        if (x == L){
            print(cnt, 1);
            return;
        }
        if (y == L){
            print(-1, 0);
            return;
        }
    }
    cnt = max(0ll, cnt);
    int l = -1, r = cnt, ans = -2, val;
    //cout << dijk(cnt, 1);
    while (l <= r){
        int m = (l+r)/2;
        if (dijk(m, 1) <= L){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    //cout << "11w";
    if (ans == -2){
        cout << "NO\n";
        return;
    }
    //cout << "FJ " << ans << endl;
    
    l = 1, r = 2e12, val = 1;
    while (l <= r){
        int m = (l+r)/2;
        if (dijk(ans, m) <= L){
            val = m;
            //cout << "GOT " << val << endl;
            l = m+1;
        }else{
            r = m-1;
        }
    }
    print(ans, val);
}

signed main(){
    FAST_IO;
    int TC = 1;
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}