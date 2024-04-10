//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E9;
const ll MOD = 1E9+7;
ll A[DIM],ctt[DIM];
map<ll,ll> M[DIM];
map<ll,ll> cur;
map<pair<ll,ll>,ll> lvl;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q;
    cin>>n>>q;
    ll gcd = 0;
    for(ll i = 1;i<=n;++i){

        cin>>A[i];
        if (i==1)gcd = A[i];
        gcd = __gcd(A[i],gcd);
        ll x = A[i];
        for(ll div = 2;div*div<=x;++div){
            if (x%div)continue;
            ll cnt = 0;
            while(x%div==0){
                x/=div;
                ++cnt;
            }
            M[i][div] = cnt;
            if (cur.count(div)==0)cur[div] = cnt;
            cur[div] = min(cur[div],cnt);
            lvl[{div,cnt}]++;
            ctt[div]++;
        }
        if (x!=1){
            ll div = x,cnt = 1;
            M[i][div] = cnt;
            if (cur.count(div)==0)cur[div] = cnt;
            cur[div] = min(cur[div],cnt);
            lvl[{div,cnt}]++;
            ctt[div]++;
        }
    }
    for(ll i = 1;i<DIM;++i){
        if (ctt[i]!=n)cur[i] = 0;
    }
    while(q--){
        ll pos,x;
        cin>>pos>>x;
        for(ll div = 2;div*div<=x;++div){
            if (x%div)continue;
            ll cnt = 0;
            while(x%div==0){
                x/=div;
                ++cnt;
            }
            if (M[pos].count(div))
                lvl[{div, M[pos][div]}]--;
            else
                ++ctt[div];

            M[pos][div]+=cnt;
            lvl[{div,M[pos][div]}]++;
           // cout<<lvl[{div,cur[div]}]<<' '<<cur[div]<<endl;
            while(ctt[div]==n && lvl[{div,cur[div]}]==0){
                ++cur[div];
                gcd = (gcd*div)%MOD;
            }
        }
        if (x!=1){
            ll div = x;
            ll cnt = 1;
            if (M[pos].count(div))
                lvl[{div,M[pos][div]}]--;
            else ++ctt[div];
            M[pos][div]+=cnt;
            lvl[{div,M[pos][div]}]++;
            while(ctt[div]==n && lvl[{div,cur[div]}]==0){
                ++cur[div];
                gcd = (gcd*div)%MOD;
            }
        }
        cout<<gcd<<endl;

    }
    return 0;
}