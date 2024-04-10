/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<ii, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> vc1[maxN];
vector<ii> vc2[maxN];
ii temp[maxN];

ii oldass[maxN];

int sub[maxN];
int team[maxN];
int unholy[maxN];
vector<int> crew;

void dfs_sub(int node, int par){
    crew.pb(node);
    sub[node] = 1;
    for(int cc : vc1[node]) if(cc != par){
        dfs_sub(cc, node); sub[node] += sub[cc];
    }
}

void dfs_team(int node, int par){
    team[node] = z;
    for(int cc : vc1[node]) if(cc != par) dfs_team(cc, node);
}

void dfs_unholy(int node, int par){
    for(ii cc : vc2[node]) if(cc.fi != par){
        if(team[node] != team[cc.fi]){
            unholy[cc.se] = cc.fi;
        }
        dfs_unholy(cc.fi, node);
    }
}

void decom(int root, vector<iii> stk){
    crew.clear();
    dfs_sub(root, root);
    int sz = crew.size();
    if(crew.size() == 2){
        int z = stk[0].se;
        ii pr = stk[0].fi;
        cout << pr.fi << " " << pr.se << " " <<
            oldass[z].fi << " " << oldass[z].se << endl;
        return;
    }
    // cout << root << endl;
    while(1){
        int suc = 0;
        for(int cc : vc1[root]) if(sub[cc] < sub[root]){
            if(sub[cc] * 2 > sz) suc = cc;
        }
        if(suc) root = suc;
        else break;
    }
    z = 0;
    team[root] = 0;
    for(int cc : vc1[root]){
        ++z; dfs_team(cc, root);
    }
    vector<vector<iii>> mortal;
    mortal.resize(z + 1);
    for(iii cac : stk){
        x = cac.fi.fi;
        y = cac.fi.se;
        z = cac.se;
        vc2[x].pb(ii(y, z));
        vc2[y].pb(ii(x, z));
    }
    for(iii cc : stk) unholy[cc.se] = 0;
    dfs_unholy(root, root);
    for(int cc : crew) vc2[cc].clear();
    for(iii cac : stk){
        x = cac.fi.fi;
        y = cac.fi.se;
        z = cac.se;
        if(unholy[z]){
            if(x == unholy[z]) y = root;
            else x = root;
        }
        mortal[max(team[x], team[y])].pb({ii(x, y), z});
    }
    vector<int> vus = vc1[root]; vc1[root].clear();
    for(int cc : vus){
        vc1[root].pb(cc);
        decom(root, mortal[team[cc]]);
        vc1[root].pop_back();
    }
    vc1[root] = vus;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 2, n){
        cin >> x >> y;
        vc1[x].pb(y);
        vc1[y].pb(x);
    }
    vector<iii> sexab;
    for1(i, 2, n){
        cin >> x >> y;
        oldass[i] = {x, y};
        sexab.pb({ii(x, y), i});
    }
    cout << n - 1 << endl;
    decom(1, sexab);

}