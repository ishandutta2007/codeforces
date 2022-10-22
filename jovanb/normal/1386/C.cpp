#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;

int ea[MAXN+5];
int eb[MAXN+5];

struct DSU{
    int n;
    int par[MAXN+5];
    bool col[MAXN+5];
    int rnk[MAXN+5];
    struct operacija{
        int a, b, rnka, rnkb;
    };
    stack <operacija> ops;
    void init(){
        for(int i=1; i<=n; i++){
            par[i] = i;
        }
    }
    int root(int x){
        return x == par[x] ? x : root(par[x]);
    }
    int color(int x){
        if(x == par[x]) return 0;
        if(col[x]) return 1^color(par[x]);
        return color(par[x]);
    }
    bool add(int a, int b){
        //cout << "Dodajem " << a << " " << b << "\n";
        int a1 = root(a);
        int b1 = root(b);
        if(a1 == b1){
            /// grana
            ops.push({0, 0, 0, 0});
            return color(a) != color(b);
        }
        if(rnk[a1] < rnk[b1]) swap(a1, b1);
        ops.push({a1, b1, rnk[a1], rnk[b1]});
        if(rnk[a1] == rnk[b1]) rnk[a1]++;
        if(color(a) == color(b)) col[b1] = 1;
        par[b1] = a1;
        return 1;
    }
    void brisi(){
        operacija op = ops.top();
        //cout << "Brisem\n";
        ops.pop();
        int a = op.a;
        int b = op.b;
        rnk[a] = op.rnka;
        rnk[b] = op.rnkb;
        par[a] = a;
        par[b] = b;
        col[a] = col[b] = 0;
    }
} dsu;

int sol[MAXN+5];

void resi(int l, int r, int tl, int tr){
    if(l > r) return;
    int mid = (l+r)/2;
    //cout << l << " " << r << " " << tl << " " << tr << " " << mid << "\n";
    bool moze = 1;
    for(int i=r; i>mid; i--){
        dsu.add(ea[i], eb[i]);
    }
    /*if(!moze){
        for(int i=mid+1; i<=r; i--) dsu.brisi();
        resi(mid+1, r, tl, tr);
        return;
    }*/
    int brd;
    for(brd = tl; brd<mid; brd++){
        if(!dsu.add(ea[brd], eb[brd])){
            dsu.brisi();
            break;
        }
    }
    sol[mid] = brd;
    for(int i=brd-1; i>=tl; i--) dsu.brisi();
    dsu.add(ea[mid], eb[mid]);
    resi(l, mid-1, tl, sol[mid]);
    dsu.brisi();
    for(int i=r; i>mid; i--) dsu.brisi();
    for(int i=brd-1; i>=tl; i--){
        dsu.add(ea[i], eb[i]);
    }
    resi(mid+1, r, sol[mid], tr);
    for(int i=brd-1; i>=tl; i--) dsu.brisi();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++){
        cin >> ea[i] >> eb[i];
    }
    dsu.n = n;
    dsu.init();
    int bord = m;
    for(int i=m-1; i>=1; i--){
        if(!dsu.add(ea[i+1], eb[i+1])){
            bord = i+1;
            break;
        }
        if(i == 1) bord = 1;
    }
    for(int i=max(2, bord); i<=m; i++) dsu.brisi();
    resi(bord, m, 1, m);
    //for(int i=1; i<=m; i++) cout << sol[i] << " " << i << endl;
    for(int i=1; i<=q; i++){
        int x, y;
        cin >> x >> y;
        if(sol[y] >= x) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

/*
5 7 1
1 2
2 3
3 4
4 5
1 3
2 4
3 5
3 4

*/