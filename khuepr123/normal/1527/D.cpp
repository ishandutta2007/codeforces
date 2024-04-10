#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> vc[maxN];
int ans[maxN];

int dfs_fake(int node, int par){
    if(node == 2) z = par;
    int val = 1;
    for(int child : vc[node]){
        if(child == par) continue;
        int gg = dfs_fake(child, node);
        if(node == 1){
            if(gg >= mod){
                gg -= mod; // gg subtree ct2 k = 2
                y = (gg + 1 - k) * (n - gg);
            }
            x += (gg * (gg - 1));
        }
        val += gg;
    }
    if(node == 2){
        k = val; val += mod;
    }
    return val;
}

void del(int ind, int erz){
    for1(i, 0, vc[ind].size() - 1){
        if(vc[ind][i] == erz){
            vc[ind].erase(vc[ind].begin() + i); break;
        }
    }
}

int in[maxN];
int out[maxN];
int cnt = 0;
void dfs(int node, int par){
    in[node] = ++cnt;
    for(int child : vc[node]){
        if(child == par) continue;
        dfs(child, node);
    }
    out[node] = ++cnt;
}

bool cover(int n1, int n2){
    if(in[n1] <= in[n2] && out[n1] >= out[n2])
    return 1; return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n; for1(i, 0, n + 3){
            vc[i].clear(); ans[i] = 0;
        }
        for1(i, 2, n){
            cin >> x >> y; ++x; ++y;
            vc[x].pb(y);
            vc[y].pb(x);
        }
        x = 0; y = 0;
        dfs_fake(1, 0);
        ans[0] = x / 2; ans[1] = 0;
        vc[n + 2].pb(z); vc[n + 2].pb(2);
        del(2, z); del(z, 2);
        dfs(n + 2, n + 2);
        in[n + 1] = 0; out[n + 1] = 0;
        // pointer x, y
        x = 1; y = 2;
        for1(i, 2, n){
                 if(cover(x, i)) x = i;
            else if(cover(y, i)) y = i;
            else{
                if(cover(i, x) || cover(i, y)){}
                else break;
            }
            if(cover(i + 1, x) || cover(i + 1, y)){
                ans[i] = 0; continue;
            }
            // cout << x << " " << y << endl;
            int v1 = (out[x] - in[x] + 1) / 2;
            int v2 = (out[y] - in[y] + 1) / 2;
            int v3 = (out[i + 1] - in[i + 1] + 1) / 2;
            if(cover(x, i + 1)) v1 -= v3;
            if(cover(y, i + 1)) v2 -= v3;
            ans[i] = v1 * v2;
        }
        int total = 0;
        for1(i, 0, n){
            total += ans[i];
        }
        ans[1] = (n * (n - 1)) / 2 - total;
        for1(i, 0, n){ cout << ans[i] << " ";}
        cout << endl;
    }
}