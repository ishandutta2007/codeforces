#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e17;

ll n,k,A[DIM],pref[DIM],suf[DIM];
map<ll,ll> M;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    forn(i,n){
        cin>>A[i];

    }
    sort(A+1,A+1+n);
    ll cnt = 0;
    ll res1 = 0;
    forn(i,n){

        res1+=(A[i]-A[i-1])*cnt;
        cnt++;

        pref[i] = res1;
        pref[i] = max(A[i+1]-1-A[i],0ll)*cnt+res1;
    }
    cnt = 0;
    ll res2 = 0;
    for(ll i = n;i>=1;i--){

        res2+=(A[i+1]-A[i])*cnt;
        cnt++;

        suf[i] = max(A[i]-1-A[i-1],0ll)*cnt+res2;

    }
    ll res = INF;
    forn(i,n){
        ll ct = 1;
        ll st = i-1;
        while(i<n && A[i]==A[i+1]){
            i++;
            ct++;
        }
        if (ct>=k){
            cout<<0<<endl;
            return 0;
        }

        ll r = pref[st];
        if (st+ct>=k){
            r+=(k-ct);
            res = min(res,r);
        }
        r =0;
        r = suf[i+1];
        if (n-i+ct>=k){
            r+=(k-ct);
            res = min(res,r);
        }
        r = 0;
        r = suf[i+1]+pref[st];
        ll need = max(0ll,k-ct);

        r+=min(need,st);
        need-=min(need,st);
        r+=min(need,n-i);
        need-=min(need,n-i);
        if (need==0)res=  min(res,r);

        //cout<<res<<' ';
    }
    cout<<res<<endl;
    return 0;
}