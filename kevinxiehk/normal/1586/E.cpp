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
vector<int> conn[300005];
int fa[300005];
int dep[300005];
int cnt[300005];
int n, m;
int dsu[300005];
int f(int x) {
    if(dsu[x] == x) return x;
    return dsu[x] = f(dsu[x]);
}
void dfs(int now, int par) {
    fa[now] = par;
    for(auto x: conn[now]) {
        if(x != par) {
            dep[x] = dep[now] + 1;
            dfs(x, now);
        }
    }
}
vector<int> path(int a, int b) {
    queue<int> fnt;
    stack<int> bk;
    while(a != b) {
        //cout << a << ' ' << b << '\n';
        if(dep[a] > dep[b]) {
            fnt.push(a);
            cnt[a]++;
            a = fa[a];
        }
        else {
            bk.push(b);
            cnt[b]++;
            b = fa[b];
        }
    }
    fnt.push(a);
    vector<int> ret;
    while(!fnt.empty()) {
        ret.pb(fnt.front());
        fnt.pop();
    }
    while(!bk.empty()) {
        ret.pb(bk.top());
        bk.pop();
    }
    return ret;
}
int ccc = 0;
int dfs2(int now, int par) {
    int ccnt = 0;
    for(auto x: conn[now]) {
        if(x != par) ccnt += dfs2(x, now);
    }
    ccc += ccnt / 2;
    if(ccnt % 2 == 1) {
        if(cnt[now] % 2 == 0) ccc++;
    }
    return cnt[now] % 2;
}
void solve(int TC) {
    cin >> n >> m;
    for(int i = 0; i <= n; i++) dsu[i] = i;
    int t, tt;
    while(m--) {
        cin >> t >> tt;
        if(f(t) != f(tt)) {
            //cout << t << ' ' << tt << '\n';
            conn[t].pb(tt);
            conn[tt].pb(t);
            dsu[f(t)] = dsu[f(tt)];
        }
    }
    dep[1] = 1;
    dfs(1, 1);
    //for(int i = 1; i <= n; i++) cout << fa[i] << ' '; cout << '\n';
    int q;
    cin >> q;
    int a, b;
    vector<vector<int>> ans;
    while(q--) {
        cin >> a >> b;
        ans.pb(path(a, b));
    }
    bool can = true;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] % 2 == 1) can = false;
    }
    if(can) {
        cout << "YES\n";
        for(auto x: ans) {
            cout << x.size() << '\n';
            for(auto xx: x) cout << xx << ' ';
            cout << '\n';
        }
        return;
    }
    cout << "NO\n";
    dfs2(1, 1);
    cout << ccc << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}