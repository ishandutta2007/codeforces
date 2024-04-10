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
const ll DIM = 1E5+7;
const ll INF = 1e18;
ll A[DIM],B[DIM];
ll sign (ll x){
    if (x>0)return 1;
    if (x<0)return -1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll f1 = 0,f2 = 0;
        forn(i,n){
            cin>>A[i];
            if (A[i]>0)f1++;
            if (A[i]<0)f2 ++;
        }

        forn(i,n){
            cin>>B[i];
        }
        ll flag = 0;
        for(ll i = n;i>=1;--i){
            if (A[i]==1)f1--;
            if (A[i]==-1)f2--;
            if(B[i]-A[i]>0&& A[i]!=B[i] && f1==0){
                flag = 1;
                break;
            }
            if (B[i]-A[i]<0 && A[i]!=B[i] && f2==0){
                flag = 1;
                break;
            }
        }
        if (flag==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}