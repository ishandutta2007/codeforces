/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN], b[maxN], c[maxN];
int x, y, z, k;

vector<iii> qry[maxN];

int tree[maxN * 4];
int lazy[maxN * 4];
int l[maxN * 4], r[maxN * 4];

void build(int node, int left, int right){
    l[node] = left; r[node] = right; tree[node] = 0;
    if(left == right) return;
    int mid = (left + right) >> 1;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

int ival;

void inc(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        tree[node] += ival; lazy[node] += ival; return;
    }
    int mid = r[node * 2];
    inc(node * 2, left, min(mid, right));
    inc(node * 2 + 1, max(left, mid + 1), right);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1])
     + lazy[node];
}

ii token(){
    ii ans = {0, 0};
    build(1, 1, maxN - 5);
    for1(i, 1, maxN - 5){
        for(iii cc : qry[i]){
            ival = cc.fi; inc(1, cc.se.fi, cc.se.se);
        }
        ans = max(ans, ii(tree[1], i));
        qry[i].clear();
    }
    return ans;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> x >> y >> z;
        a[i] = x; b[i] = y; c[i] = z;
        qry[x].pb({1, ii(y, z)});
        qry[y + 1].pb({-1, ii(y, z)});
    }
    ii ans = token();
    cout << ans.fi << endl;
    for1(i, 1, n) if(a[i] <= ans.se && ans.se <= b[i]){
        y = b[i]; z = c[i];
        qry[y].pb({1, ii(y, z)});
        qry[z + 1].pb({-1, ii(y, z)});
    }
    ii ans2 = token();
    for1(i, 1, n){
        x = a[i]; y = b[i]; z = c[i];
        if(x <= ans.se && ans.se <= y && y <= ans2.se && ans2.se <= z){
            cout << i << " ";
        }
    }
    cout << endl;
}