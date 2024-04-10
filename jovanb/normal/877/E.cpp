#include <bits/stdc++.h>
using namespace std;

int in[200005];
int out[200005];
int par[200005];
int seg[1000005];
int lazy[1000005];
int niz[200005];

int cnt;
vector <int> graf[200005];

void dfs(int v){
    in[v] = ++cnt;
    for(auto c : graf[v]){
        dfs(c);
    }
    out[v] = cnt;
}

void init(int node, int l, int r){
    if(l == r){
        seg[node] = niz[l];
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    seg[node] = seg[node*2] + seg[node*2+1];
}

void propagate(int node, int l, int r){
    lazy[node] %= 2;
    if(lazy[node]){
        seg[node] = (r-l+1) - seg[node];
        lazy[node] = 0;
        if(l != r){
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
    }
}

void upd(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(l > tr || tl > r) return;
    if(tl <= l && r <= tr){
        seg[node] = (r-l+1) - seg[node];
        if(l != r){
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr);
    upd(node*2+1, mid+1, r, tl, tr);
    seg[node] = seg[node*2] + seg[node*2+1];
}

int query(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(l > tr || tl > r) return 0;
    if(tl <= l && r <= tr){
        return seg[node];
    }
    int mid = (l+r)/2;
    return query(node*2, l, mid, tl, tr) + query(node*2+1, mid+1, r, tl, tr);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=2; i<=n; i++){
        cin >> par[i];
        graf[par[i]].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        niz[in[i]] = x;
    }
    init(1, 1, n);
    int m;
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s == "pow"){
            int x;
            cin >> x;
            upd(1, 1, n, in[x], out[x]);
        }
        else{
            int x;
            cin >> x;
            cout << query(1, 1, n, in[x], out[x]) << "\n";
        }
    }
    return 0;
}