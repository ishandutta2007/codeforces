#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll x[1000005];
ll y[1000005];
ll res[1000005];
ll sumx[1000005];
ll sumy[1000005];

struct strukt{
    ll x;
    ll y;
    ll ind;
} niz[1000005];

bool cmp(strukt a, strukt b){
    return a.y-a.x < b.y-b.x;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        niz[i].x = x[i];
        niz[i].y = y[i];
        niz[i].ind = i;
    }
    sort(niz+1, niz+1+n, cmp);
    for(int i=1; i<=n; i++){
        res[niz[i].ind] += (i-1)*niz[i].x+sumy[i-1];
        sumy[i] = sumy[i-1]+niz[i].y;
    }
    for(int i=n; i>=1; i--){
        res[niz[i].ind] += (n-i)*niz[i].y+sumx[i+1];
        sumx[i] = sumx[i+1]+niz[i].x;
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        int r = min(x[a]+y[b], x[b]+y[a]);
        res[a] -= r;
        res[b] -= r;
    }
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}