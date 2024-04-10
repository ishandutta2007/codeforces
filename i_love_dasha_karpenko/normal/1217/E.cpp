#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll DIM2 = 1E6+7;
const ll INF = 2E9+140;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
const ll masksz = po(11)-1;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


ll n,m;

ll A[DIM];
pp T[DIM*4][10];
void init(ll t){
    for(ll i = 0;i<10;++i){
        pp p1 = T[t*2+1][i];
        pp p2 = T[t*2+2][i];
        if ((p1.fi<p2.fi || p2.fi==-1) && p1.fi!=-1){
            T[t][i].fi = p1.fi;
            swap(p1.fi,p1.sc);
        }
        else if (p2.fi!=-1){
            T[t][i].fi = p2.fi;
            swap(p2.fi,p2.sc);
        }
        else{
            T[t][i] = {-1,-1};
            continue;
        }
        if ((p1.fi<p2.fi || p2.fi==-1) && p1.fi!=-1){
            T[t][i].sc = p1.fi;
            swap(p1.fi,p1.sc);
        }
        else if (p2.fi!=-1){
            T[t][i].sc = p2.fi;
            swap(p2.fi,p2.sc);
        }
        else{
            T[t][i].sc = -1;
        }
    }
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        ll x = A[tl];
        for(ll i = 0;i<10;++i){
            if (x%10)T[t][i].fi = A[tl];
            else T[t][i].fi = -1;
            T[t][i].sc = -1;
            x/=10;
        }
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    init(t);

}
void update(ll t,ll tl,ll tr,ll pos,ll val){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        A[tl] = val;
        ll x = A[tl];
        for(ll i = 0;i<10;++i){
            if (x%10)T[t][i].fi = A[tl];
            else T[t][i].fi = -1;
            T[t][i].sc = -1;
            x/=10;
        }
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    init(t);
}
pp query(ll t,ll tl,ll tr,ll l,ll r,ll p){
    if (tl>r || l>tr)return {-1,-1};
    if (l<=tl && tr<=r)return T[t][p];
    ll tm = (tl+tr)/2;
    pp p1 = query(t*2+1,tl,tm,l,r,p);
    pp p2 = query(t*2+2,tm+1,tr,l,r,p);
    pp pr;
    if ((p1.fi<p2.fi || p2.fi==-1) && p1.fi!=-1){
        pr.fi = p1.fi;
        swap(p1.fi,p1.sc);
    }
    else if (p2.fi!=-1){
        pr.fi = p2.fi;
        swap(p2.fi,p2.sc);
    }
    else{
        pr = {-1,-1};
        return pr;
    }
    if ((p1.fi<p2.fi || p2.fi==-1) && p1.fi!=-1){
        pr.sc = p1.fi;
        swap(p1.fi,p1.sc);
    }
    else if (p2.fi!=-1){
        pr.sc = p2.fi;
        swap(p2.fi,p2.sc);
    }
    else{
        pr.sc = -1;
    }
    return pr;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    forn(i,n){
        cin>>A[i];
    }

    buildtree(0,1,n);
    forn(quer,m){
        ll type;
        cin>>type;
        if (type==1){
            ll pos,num;
            cin>>pos>>num;
            update(0,1,n,pos,num);
        }
        else{
            ll l,r;
            cin>>l>>r;
            ll res = INF;
            for(ll i = 0;i<10;++i){
                pp ret = query(0,1,n,l,r,i);
                if(ret.fi!=-1 && ret.sc!=-1)res = min(res,ret.fi+ret.sc);
            }
            if (res==INF)cout<<"-1\n";
            else cout<<res<<endl;
        }
    }
    return 0;
}