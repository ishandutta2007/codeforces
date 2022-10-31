//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E6+7;
const ll MAXN = 1E6;
ll T[DIM*4],A[DIM][2],mx[DIM*4];

void update(ll t,ll tl,ll tr,ll pos,ll delta) {
    if (tl > pos || tr < pos)
        return;
    if (tl==tr){
        T[t]+=delta;
        mx[t] = T[t];
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,delta);
    update(t*2+2,tm+1,tr,pos,delta);
    T[t] = T[t*2+1]+T[t*2+2];
    mx[t] = max(mx[t*2+1]+T[t*2+2],mx[t*2+2]);
}
ll query(ll t,ll tl,ll tr,ll left){
    if (mx[t]+left<=0)
        return -1;
    if (tl==tr)
        return tl;
    ll tm = (tl+tr)/2;
    ll ans = query(t*2+2,tm+1,tr,left);
    if (ans!=-1)
        return ans;
    left+=T[t*2+2];
    return query(t*2+1,tl,tm,left);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        A[i][0] = x;
        update(0, 1, MAXN, x,1);
    }
    for (ll i = 1; i <= m; ++i) {
        ll x;
        cin >> x;
        A[i][1] = x;
        update(0, 1, MAXN, x, -1);
    }
    ll q;
    cin>>q;
    while(q--){
        ll type,pos,val;
        cin>>type>>pos>>val;
        update(0,1,MAXN,A[pos][type-1],(type==1?-1:1));
        A[pos][type-1] = val;
        update(0,1,MAXN,A[pos][type-1],(type==1?1:-1));
        cout<<query(0,1,MAXN,0)<<endl;
    }
    return 0;
}