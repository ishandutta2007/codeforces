//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll A[DIM],pref[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,q,k;
    cin>>n>>q>>k;
    for(ll i = 1;i<=n;++i) {
        cin>>A[i];
        pref[i] = pref[i-1];
        if (i>1){
            pref[i]+=A[i]-A[i-2]-2;
        }
    }
    for(ll i = 1;i<=q;++i){
        ll l,r;
        cin>>l>>r;
        if (r-l==0){
            cout<<k-1<<endl;
            continue;
        }
        ll ans = pref[r]-pref[l+1];
        ans+=A[l+1]-2;
        ans+=k-A[r-1]-1;
        cout<<ans<<endl;
    }


    return 0;
}