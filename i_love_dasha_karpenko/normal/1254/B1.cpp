#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 10E4+7;
const ll INF = 10E16;
vector<ll> V;
ll sz;
ll F(ll div){
    ll res = 0;
    for(ll i = 0;i+div<=sz;i+=div){
        ll p1 = i;
        ll p2 = i+div-1;
        ll l1 = V[p1];
        ll l2 = V[p2];
        ll s1 = 1,s2 = 1;
        while(p1!=p2){
            if (s1>s2){
                res+=(l2-V[p2-1])*s2;
                l2 = V[p2-1];
                p2--;
                s2++;
            }
            else{
                res+=(V[p1+1]-l1)*s1;
                l1 = V[p1+1];
                p1++;
                s1++;
            }
        }
    }
    return res;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;

    forn(i,n){
        ll x;
        cin>>x;
        if (x!=0)V.pb(i);
    }
    ll sq = V.size();sz = V.size();
    if (sz==0){
        cout<<0<<endl;
        return 0;
    }
    sq = sqrt(sq);
    ll res= INF;
    for(ll div = 2;div<=sq;div++){
        if (sz%div==0){
            res = min(res,F(div));
            res = min(res,F(sz/div));
        }
    }
    if (sz>1)
    res = min(res,F(sz));
    if (res==INF)cout<<"-1\n";
    else
    cout<<res<<endl;
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3