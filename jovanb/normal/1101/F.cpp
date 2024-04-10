#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x[100005];

ll INF = 1000000000000000000LL;

struct kamion{
    ll s, f, c, r;
} niz[250005];

bool check(int koji, ll v){
    ll tren = v;
    ll u = 0;
    for(int i=niz[koji].s; i<niz[koji].f; i++){
        ll dis = x[i+1]-x[i];
        if(dis*niz[koji].c > v) return 0;
        if(dis*niz[koji].c > tren){
            u++;
            tren = v;
        }
        tren -= dis*niz[koji].c;
    }
    return u <= niz[koji].r;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }
    for(int i=1; i<=m; i++){
        cin >> niz[i].s >> niz[i].f >> niz[i].c >> niz[i].r;
    }
    random_shuffle(niz+1, niz+m+1);
    ll mn = 0;
    for(int i=1; i<=m; i++){
        if(check(i, mn)) continue;
        ll l = mn+1, r = INF, u = INF;
        while(l <= r){
            ll mid = (l+r)/2;
            if(check(i, mid)){
                r = mid-1;
                u = mid;
            }
            else l = mid+1;
        }
        mn = max(mn, u);
    }
    cout << mn;
    return 0;
}