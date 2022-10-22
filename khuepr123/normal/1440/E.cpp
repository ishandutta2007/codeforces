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
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int tree[maxN * 4];
int lazy[maxN * 4];
int mn[maxN * 4];
int numele[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];

inline void push(int node){
    if(lazy[node]){
        if(l[node] == r[node]){
            tree[node] = lazy[node];
            mn[node] = lazy[node];
            lazy[node] = 0;
        }
        else{
            tree[node] = lazy[node] * numele[node];
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
            mn[node] = lazy[node];
            lazy[node] = 0;
        }
    }
}

inline void redate(int node){
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
}

void build(int node, int left, int right){
    numele[node] = right - left + 1;
    l[node] = left;
    r[node] = right;
    if(left == right){
        tree[node] = a[left];
        mn[node] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
    redate(node);
}

void mux(int node, int left, int right){
    if(left > right) return;
    push(node);
    if(left == l[node] && right == r[node]){
        lazy[node] = y;
        push(node);
        return;
    }
    push(node * 2);
    push(node * 2 + 1);
    int mid = (l[node] + r[node]) / 2;
    mux(node * 2, left, min(mid, right));
    mux(node * 2 + 1, max(left, mid + 1), right);
    redate(node);
}

int chop;
int pinpoint(int node, int val){
    push(node);
    int mid = (l[node] + r[node]) / 2;
    if(chop > mid) return pinpoint(node * 2 + 1, val);
    if(l[node] == r[node]) return l[node];
    push(node * 2);
    push(node * 2 + 1);
    if(mn[node * 2] <= val) return pinpoint(node * 2, val);
    return pinpoint(node * 2 + 1, val);
}

// y is money, x is pivot
int ans;

void deck(int node){
    push(node);
    if(l[node] == r[node]) return;
    push(node * 2);
    push(node * 2 + 1);
    if(tree[node * 2] <= y){
        y -= tree[node * 2];
        ans += numele[node * 2];
        chop = max(chop, r[node * 2] + 1);
        deck(node * 2 + 1);
    }
    else deck(node * 2);
}

bool term;

void fung(int node, int left, int right){
    if(term) return;
    if(left > right) return;
    // cout << node << " " << left << " " << right << " ";
    // cout << l[node] << " " << r[node] << endl;
    push(node);
    if(left == l[node] && right == r[node]){
        if(tree[node] <= y){
            y -= tree[node];
            ans += numele[node];
            chop = max(chop, r[node] + 1);
            return;

        }
        term = 1;
        deck(node);
        return;
    }
    int mid = (l[node] + r[node]) / 2;
    fung(node * 2, left, min(mid, right));
    fung(node * 2 + 1, max(left, mid + 1), right);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; int o; cin >> o;
    memset(a, 0, sizeof(a));
    memset(lazy, 0, sizeof(lazy));
    for1(i, 1, n){
        cin >> a[i - 1];
    }
    build(1, 0, n - 1);
    while(o--){
        cin >> z >> x >> y; --x;
        if(z == 2){
            ans = 0;
            chop = x;
            for1(dumb, 1, 31){
                if(chop == n) break;
                int id = pinpoint(1, y);
                term = 0;
                fung(1, id, n - 1);
            }
            cout << ans << endl;
        }
        else{
            chop = 0;
            int id = pinpoint(1, y);
            mux(1, id, x);
        }
    }
}