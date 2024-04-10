/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

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

int tree[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    tree[node] = -1;
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
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

int mex(int node, int pin){
    if(l[node] == r[node]) return l[node];
    if(tree[node * 2] <= pin) return mex(node * 2, pin);
    return mex(node * 2 + 1, pin);
}

set<int> st;
int last[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    build(1, 1, maxN - 1);
    for1(i, 1, n) cin >> a[i];
    for1(i, 1, n){
        int &ls = last[a[i]];
        if(ls + 1 < i){
            st.insert(mex(1, ls));
            // cout << ls + 1 << " " << i << " " << mex(1, ls) << endl;
        }
        upd(1, a[i], i);
        ls = i;
    }
    for1(i, 1, n + 1){
        int &ls = last[i];
        if(ls < n){
            st.insert(mex(1, ls));
            // cout << ls + 1 << " " << n << endl;
        }
    }
    for1(i, 1, maxN) if(st.find(i) == st.end()){
        cout << i << endl; return 0;
    }
}