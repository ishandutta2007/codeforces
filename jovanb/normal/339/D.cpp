#include <bits/stdc++.h>
using namespace std;

int niz[1000000];
int seg[1000000];
int poz[1000000];
int par[1000000];

void zasadi(int ind, int br, int pom){
    if(br == 0) {poz[pom] = ind; seg[ind] = niz[pom]; return;}
    par[2*ind+1] = ind;
    par[2*ind+2] = ind;
    zasadi(2*ind+1, br-1, pom);
    zasadi(2*ind+2, br-1, pom+pow(2,br-1));
    if(br%2 == 1) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}

void kveri(int x, int br){
    if(br%2 == 0) seg[x] = seg[2*x+1] ^ seg[2*x+2];
    else seg[x] = seg[2*x+1] | seg[2*x+2];
    if(x == 0) return;
    kveri(par[x], br+1);
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m, x;
    cin >> n >> m;
    x = pow(2,n);
    for(int i=0; i<x; i++) cin >> niz[i];
    zasadi(0, n, 0);
    while(m--){
        int p, b;
        cin >> p >> b;
        seg[poz[p-1]] = b;
        kveri(par[poz[p-1]], 1);
        cout << seg[0] << "\n";
    }
    return 0;
}