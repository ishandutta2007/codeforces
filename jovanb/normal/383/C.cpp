#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int in[200005];
int out[200005];
int cnt;
int niz1[200005];
int niz2[200005];
int niz[200005];
bool visited[200005];
int gde[200005];
int seg[5][1000005];
vector <int> graf[200005];

void dfs(int v, int depth){
    in[v] = ++cnt;
    visited[v] = 1;
    if(depth%2){niz2[in[v]] = niz[v]; gde[v] = 2;}
    else {niz1[in[v]] = niz[v]; gde[v] = 1;}
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c, depth+1);
    }
    out[v] = cnt;
}

void init(int node, int l, int r){
    if(l == r){
        seg[1][node] = niz1[l];
        seg[2][node] = niz2[l];
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

void upd(int koji, int node, int l, int r, int tl, int tr, int val){
    if(l > tr || tl > r) return;
    if(tl <= l && r <= tr){
        seg[koji][node] += val;
        seg[3-koji][node] -= val;
        return;
    }
    int mid = (l+r)/2;
    upd(koji, node*2, l, mid, tl, tr, val);
    upd(koji, node*2+1, mid+1, r, tl, tr, val);
}

int query(int koji, int node, int l, int r, int x){
    if(l == r){
        return seg[koji][node];
    }
    int mid = (l+r)/2;
    seg[koji][node*2] += seg[koji][node];
    seg[koji][node*2+1] += seg[koji][node];
    seg[koji][node] = 0;
    if(l <= x && x <= mid) return query(koji, node*2, l, mid, x);
    else return query(koji, node*2+1, mid+1, r, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    init(1, 1, n);
    while(m--){
        int q;
        cin >> q;
        if(q == 1){
            int x, val;
            cin >> x >> val;
            upd(gde[x], 1, 1, n, in[x], out[x], val);
        }
        else{
            int x;
            cin >> x;
            cout << query(gde[x], 1, 1, n, in[x]) << "\n";
        }
    }
    return 0;
}