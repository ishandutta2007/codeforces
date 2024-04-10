#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E6+7;
const ll MAXN = 1E10;
const ll INF = 1E18;
ll A[DIM],pref[DIM],T[DIM*4];
ll get(ll t,ll tl,ll tr,ll l,ll r,ll val){

    if (l>tr || r<tl)return -1;
    if (l<=tl && tr<=r && T[t]<val)return -1;
    if (tl==tr)return tl;
    ll tm = (tl+tr)/2;
    ll ret = get(t*2+1,tl,tm,l,r,val);
    if (ret!=-1)return ret;
    else return get(t*2+2,tm+1,tr,l,r,val);
}
ll mx(ll t,ll tl,ll tr,ll l,ll r,ll val){

    if (l>tr || r<tl)return -INF;
    if (l<=tl && tr<=r)return T[t];

    ll tm = (tl+tr)/2;
    return max(mx(t*2+1,tl,tm,l,r,val),mx(t*2+2,tm+1,tr,l,r,val));
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = pref[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = max(T[t*2+1],T[t*2+2]);
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            pref[i] = pref[i-1]+A[i];
        }
        for(ll i = n+1;i<=n*2;++i){
            A[i] = A[i-n];
            pref[i] = pref[i-1]+A[i];
        }
        buildtree(0,1,n*2);

        while((m--)>0){
            ll x;
            cin>>x;
            ll pos = 1;
            x-=A[pos];
            if (pref[n]<=0 && get(0,1,n*2,pos,pos+n,x+pref[pos])==-1){
                cout<<"-1 ";
                continue;
            }
            if (pref[n]<=0){
                cout<<get(0,1,n*2,pos,pos+n,x+pref[pos])-pos<<' ';
                continue;
            }

            ll mv = mx(0,1,n*2,1,n,x+pref[pos])-pref[pos];
            ll mxx = x-mv;
            mxx = mxx - mxx%pref[n];
            mxx = max(0ll,mxx);
            x-=mxx;

            ll res = mxx/pref[n]*n;
            if (x>mv){
                res+=n;
                x-=pref[n];
            }

            cout<<get(0,1,n*2,pos,pos+n,x+pref[pos])-pos+res<<' ';
        }
        cout<<endl;
    }
    return 0;
}