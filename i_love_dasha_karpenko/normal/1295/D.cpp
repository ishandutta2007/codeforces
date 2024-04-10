#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 10E4+7;
const ll INF = 10E17;
const ll MAXN = 29;
ll a,m,g;
vector<ll> divs;
void getdivs(ll x){
    for(ll i = 2;i<=sqrt(x);i++){
        if (x%i==0){
            divs.pb(i);
            while(x%i==0)x/=i;
        }
    }
    if (x!=1)divs.pb(x);
}
ll F(ll x){
    ll res =x/g;
    ll masksz = (1<<(divs.size()));
    for(ll mask =1;mask<masksz;mask++){
        ll pc = 0,ren = 1;
        for(ll i = 0;i<divs.size();i++){
            if (((1<<i)&mask)!=0){
                pc++;
                ren*=divs[i];
            }
            if (ren>x)break;
        }
        ren*=g;
        if (pc%2==0)res+=x/ren;
        else res-=x/ren;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt;
    cin>>tt;
    forn(q,tt){
        divs.clear();
        cin>>a>>m;
        g = __gcd(a,m);

        getdivs(m/g);
        ll res = F(a+m-1)-F(a-1);
        cout<<res<<endl;
    }
    return 0;
}
// 9 7+2