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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n;
int x, y, z, k;

vector<int> a;

int tree[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];
int lazy[maxN * 4];

void redate(int node){
    tree[node] = min(tree[node * 2] + lazy[node * 2],
                     tree[node * 2 + 1] + lazy[node * 2 + 1]);
}

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    tree[node] = 0;
    lazy[node] = 0;
    if(left == right) return;
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

int vle;

void inc(int node, int left, int right){
    if(left > right) return;
    if(l[node] == left && r[node] == right){
        lazy[node] += vle; return;
    }
    int mid = r[node * 2];
    inc(node * 2, left, min(mid, right));
    inc(node * 2 + 1, max(left, mid + 1), right);
    redate(node);
}

int sz[maxN];
vector<int> vc[maxN];
int sum[maxN];
int avg[maxN];

int findpos(int remo, int deno){
    int ps = upper_bound(all(a), (remo - 1) / deno) - a.begin();
    return ps;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        int m; cin >> n >> m;
        priority_queue<int> porqe;
        a.clear();
        while(n--){
            cin >> x; porqe.push(x);
        }
        for1(i, 1, m){
            a.pb(porqe.top()); porqe.pop();
        }
        n = m;
        a.pb(-oo); reverse(all(a));
        build(1, 1, n + 1);
        for1(i, 1, n){
            vle = -1; inc(1, i, n + 1);
        }
        for1(i, 1, n){
            cin >> sz[i];
            sum[i] = 0;
            vc[i].clear();
            for1(j, 1, sz[i]){
                cin >> x; vc[i].pb(x);
                sum[i] += x;
            }
            x = findpos(sum[i], sz[i]);
            vle = 1; inc(1, x, n + 1);
            avg[i] = x;
            --sz[i];
            /// note: i fking minused this dipshit value
        }
        for1(i, 1, n){
            vle = -1; inc(1, avg[i], n + 1);
            for(int cc : vc[i]){
                x = findpos(sum[i] - cc, sz[i]);
                vle = 1; inc(1, x, n + 1);
                cout << ((tree[1] + lazy[1]) >= 0);
                // cout << " " << x << endl;
                // cout << (tree[1] + lazy[1]) << endl;
                vle = -1; inc(1, x, n + 1);
            }
            vle = 1; inc(1, avg[i], n + 1);
        }
        cout << endl;
    }
}