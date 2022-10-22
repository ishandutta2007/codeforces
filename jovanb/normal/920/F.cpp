#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool neprost[1000005];
ll d[1000005];
ll segtree[2000000];
ll niz[400000];
bool segtree1[2000000];

void build(ll ind, ll l, ll r) {
    if(l == r){
        segtree[ind] = niz[l];
        if(niz[l] > 2) segtree1[ind] = false;
        else segtree1[ind] = true;
    }
    else{
        ll mid = (l+r)/2;
        build(2*ind+1, l, mid);
        build(2*ind+2, mid+1, r);
        segtree[ind] = segtree[ind*2+1] + segtree[ind*2+2];
        if(segtree1[ind*2+1] == true && segtree1[ind*2+2] == true) segtree1[ind] = true;
        else segtree1[ind] = false;
    }
}

void updateup(ll ind, ll l, ll r){
    if(l == r){
        segtree[ind] = d[segtree[ind]];
        niz[l] = d[niz[l]];
        if(segtree[ind] <= 2) segtree1[ind] = true;
    }
    else {
        ll mid = (l+r)/2;
        updateup(2*ind+1, l, mid);
        updateup(2*ind+2, mid+1, r);
        segtree[ind] = segtree[2*ind+1] + segtree[2*ind+2];
        if(segtree1[2*ind+1] == true && segtree1[2*ind+2] == true) segtree1[ind] = true;
    }
    return;
}

void update(ll ind, ll l, ll r, ll x, ll y) {
    if(x <= l && r <= y){
        if(segtree1[ind] != true){
            updateup(ind, l, r);
        }
    }
    else{
        ll mid = (l+r)/2;
        if(x <= mid) update(2*ind+1, l, mid, x, y);
        if(y >= mid+1) update(2*ind+2, mid+1, r, x, y);
        segtree[ind] = segtree[2*ind+1]+segtree[2*ind+2];
        if(segtree1[2*ind+1] == true && segtree1[2*ind+2] == true) segtree1[ind] = true;
    }

}
ll query(ll ind, ll l, ll r, ll x, ll y) {
    if(x <= l && r <= y) return segtree[ind];
    else{
        ll sum = 0;
        ll mid = (l+r)/2;
        if (x <= mid) {
            sum += query(2*ind+1, l, mid, x, y);
        }
        if (y >= mid+1){
            sum += query(2*ind+2, mid+1, r, x, y);
        }
        return sum;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    neprost[0] = 1;
    neprost[1] = 1;
    d[1] = 1;
    for(ll i=2; i<=1000000; i++) d[i] = 1;
    for(ll i=2; i<=1000000; i++){
        if(neprost[i] == 0){
            d[i] = 2;
            for(ll j=i*2; j<=1000000; j+=i){
                neprost[j] = 1;
                ll x = j;
                ll z = 0;
                while(x%i == 0){
                    x /= i;
                    z++;
                }
                d[j] *= z+1;
            }
        }
    }
    ll n, m;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        cin >> niz[i];
    }
    build(0,1,n);
    ll ti, li, ri;
    while(m--){
        cin >> ti >> li >> ri;
        if(ti == 2) cout << query(0, 1, n, li, ri) << "\n";
        else update(0, 1, n, li, ri);
    }
    return 0;
}