#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'

const ll DIM = 3E5+7;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i)cin>>A[i];
        ll res = 0;
        for(ll i = 2;i<n;++i){
            if ((A[i]>A[i-1] && A[i]>A[i+1]) || (A[i]<A[i+1] && A[i]<A[i-1]))++res;
        }
        ll ans = res;
        for(ll i = 1;i<=n;++i){
            ll c1 = 0,c2 = 0,c3 = 0;
            for(ll j = max(2ll,i-1);j<=min(n-1,i+1);++j){
                if ((A[j]>A[j-1] && A[j]>A[j+1]) || (A[j]<A[j+1] && A[j]<A[j-1]))++c1;
            }
            ll base = A[i];
            A[i] = A[i-1];
            for(ll j = max(2ll,i-1);j<=min(n-1,i+1);++j){
                if ((A[j]>A[j-1] && A[j]>A[j+1]) || (A[j]<A[j+1] && A[j]<A[j-1]))++c2;
            }
            A[i] = A[i+1];
            for(ll j = max(2ll,i-1);j<=min(n-1,i+1);++j){
                if ((A[j]>A[j-1] && A[j]>A[j+1]) || (A[j]<A[j+1] && A[j]<A[j-1]))++c3;
            }
            A[i] = base;
            ans = min(ans,res-c1+min(c2,c3));
        }
        cout<<ans<<endl;
    }
    return 0;
}