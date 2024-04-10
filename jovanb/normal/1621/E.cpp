#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

struct Segment{
    int mn, sum;
} seg[4*N+5];

void mrg(int node){
    seg[node].mn = min(seg[node*2].mn + seg[node*2+1].sum, seg[node*2+1].mn);
    seg[node].sum = seg[node*2].sum + seg[node*2+1].sum;
}

void init(int node, int l, int r){
    seg[node].mn = seg[node].sum = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

void upd(int node, int l, int r, int x, int val){
    if(l == r){
        seg[node].mn += val;
        seg[node].sum = seg[node].mn;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) upd(node*2, l, mid, x, val);
    else upd(node*2+1, mid+1, r, x, val);
    mrg(node);
}

ll sm[N+5];
int k[N+5];
vector <int> val[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    init(1, 1, N);
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        upd(1, 1, N, x, 1);
    }
    for(int i=1; i<=m; i++){
        cin >> k[i];
        val[i].clear();
        val[i].push_back(0);
        sm[i] = 0;
        for(int j=1; j<=k[i]; j++){
            int g;
            cin >> g;
            val[i].push_back(g);
            sm[i] += g;
        }
        upd(1, 1, N, (sm[i] + k[i] - 1)/k[i], -1);
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=k[i]; j++){
            upd(1, 1, N, (sm[i] + k[i] - 1)/k[i], 1);
            upd(1, 1, N, (sm[i] - val[i][j] + k[i] - 2)/(k[i] - 1), -1);
            if(seg[1].mn >= 0) cout << "1";
            else cout << "0";
            upd(1, 1, N, (sm[i] - val[i][j] + k[i] - 2)/(k[i] - 1), 1);
            upd(1, 1, N, (sm[i] + k[i] - 1)/k[i], -1);
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}