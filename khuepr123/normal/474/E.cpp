/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
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

vector<ii> pr;
int limleft[maxN];
int limright[maxN];
int dis;

int l[maxN * 4];
int r[maxN * 4];
int tree[maxN * 4];
int loc[maxN];
int track[maxN];

void build(int node, int left, int right){
    tree[node] = 0;
    l[node] = left;
    r[node] = right;
    if(left == right) return;
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

void upd(int node, int pin, int val){
    if(l[node] == r[node]) tree[node] = val;
    else{
        if(r[node * 2] >= pin) upd(node * 2, pin, val);
        else upd(node * 2 + 1, pin, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

vector<int> stk;

int splat(int node){
    if(l[node] == r[node]) return node;
    if(tree[node * 2] > tree[node * 2 + 1])
    return splat(node * 2); return splat(node * 2 + 1);
}

void range(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        stk.pb(node); return;
    }
    int mid = r[node * 2];
    range(node * 2, left, min(mid, right));
    range(node * 2 + 1, max(left, mid + 1), right);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> dis; pr.pb(ii(-oo, 0));
    if(dis == 0){
        cout << n << endl;
        for1(i, 1, n) cout << i << " ";
        return 0;
    }
    for1(i, 1, n){
        cin >> x; pr.pb(ii(x, i));
    }
    sort(pr.begin(), pr.end());
    pr.pb(ii(oo, 0));
    int le = 1, ri = 1;
    for1(i, 1, n){
        // cout << pr[i].fi << " " << pr[i].se << " ";
        x = pr[i].fi; y = pr[i].se;
        loc[y] = i;
        while(x - pr[le].fi >= dis) ++le;
        while(pr[ri].fi - x < dis) ++ri;
        limleft[y] = le - 1;
        limright[y] = ri;
        // cout << le - 1 << " " << ri << endl;
    }
    build(1, 1, n);
    tree[0] = 0;
    l[0] = 0;
    r[0] = 0;
    ii best = ii(0, 0);
    for1(i, 1, n){
        stk.clear();
        range(1, 1, limleft[i]);
        range(1, limright[i], n);
        int node = 0;
        for(int root : stk){
            int nd = splat(root);
            if(tree[nd] > tree[node]) node = nd;
        }
        track[loc[i]] = l[node];
        int res = tree[node] + 1;
        best = max(best, ii(res, loc[i]));
        upd(1, loc[i], res);
    }
    cout << best.fi << endl;
    int pn = best.se;
    vector<int> fack;
    for1(i, 1, best.fi){
        fack.pb(pn);
        pn = track[pn];
    }
    while(!fack.empty()){
        cout << pr[fack.back()].se << " "; fack.pop_back();
    }
}