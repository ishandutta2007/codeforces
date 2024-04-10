/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(falc) falc.begin(), falc.end()
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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int sparse[25][maxN];
int ans = 0;

int l[maxN * 4];
int r[maxN * 4];
int tree[maxN * 4];
vector<int> fl[maxN * 4];

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    fl[node].resize(right - left + 1);
    if(left == right) fl[node][0] = a[left];
    else{
        int mid = (left + right) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
        merge(all(fl[node * 2]), all(fl[node * 2 + 1]), fl[node].begin());
    }
}
void take(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        int val = lower_bound(all(fl[node]), y + 1) - fl[node].begin();
        ans += val; return;
    }
    int mid = r[node * 2];
    take(node * 2, left, min(mid, right));
    take(node * 2 + 1, max(left, mid + 1), right);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for1(i, 1, n){
        cin >> a[i];
    }
    ++n;
    a[n] = -1;
    map<int, int> cls;
    for2(i, n, 1){
        if(cls.find(a[i]) == cls.end()) sparse[0][i] = n;
        else sparse[0][i] = cls[a[i]];
        cls[a[i]] = i;
    }
    for1(ds, 0, 20) for1(i, 1, n){
        sparse[ds + 1][i] = sparse[ds][sparse[ds][i]];
    }
    for1(i, 1, n){
        a[i] = i;
        for1(ds, 0, 20) if((1 << ds) & k) a[i] = sparse[ds][a[i]];
    }
    build(1, 1, n);
    for1(i, 0, maxN * 4 - 1) fl[i].pb(oo);
    int o; cin >> o; while(o--){
        cin >> x >> y;
        x = (x + ans) % (n - 1) + 1;
        y = (y + ans) % (n - 1) + 1;
        if(x > y) swap(x, y);
        ans = 0;
        take(1, x, y);
        ans = (y - x + 1) - ans; cout << ans << endl;
    }
}