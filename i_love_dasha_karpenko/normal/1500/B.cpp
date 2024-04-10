//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E6+7;
const ll MAXN = 1E6;
ll A[DIM],B[DIM],rev[DIM];
vector<ll> V;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
        A[x] = i;
    }
    for(ll i = 1;i<=m;++i){
        ll x;
        cin>>x;
        B[x] = i;
    }
    ll step = n/__gcd(n,m)*m;
    memset(rev,-1,sizeof(rev));
    for(ll i = 0;i<m;++i){
        if (rev[i*n%m]==-1)rev[i*n%m] = i;
    }
    for(ll i = 1;i<=MAXN;++i){
        if (A[i]==0 || B[i]==0)continue;
        ll base = B[i]-A[i];
        base%=m;
        if (base<0)base+=m;
        if (rev[base]==-1)continue;
        ll st = rev[base]*n+A[i];
        if (st==0)st+=step;
        V.push_back(st);
        //
    }
    ll l = 0,r = 1E19;
    while(l!=r){
        ll tm = (l+r)/2;
        ll cnt = 0;
        if (tm==106){
            ll h;
            ++h;
        }
        for(ll to:V){
            cnt+=max(0ll,tm-to)/step;
            if (tm>=to)++cnt;
        }
        if (tm-cnt>=k)r = tm;
        else l = tm+1;
    }

    cout<<l<<endl;
    return 0;
}