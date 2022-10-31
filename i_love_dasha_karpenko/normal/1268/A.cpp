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
const ll DIM = 200000+7;
const ll INF = 10E17;

ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll flag = 0;
    forn(i,n){
        char ch; cin>>ch;
        A[i] = ch-'0';
        if (A[i]!=9 && i<=k)flag = 1;
    }
    ll ff = 0;
    for(ll i = k+1;i<=n;i++){
        ll g = i%k;
        if (g==0)g = k;
        if (A[i]!=A[g]){
            if (A[i]>A[g])ff = 1;
            break;
        }
    }
    if (ff==0){
        cout<<n<<endl;
        forn(i,n){
            ll g = i%k;
            if (g==0)g = k;
            cout<<A[g];
        }
        cout<<endl;
        return 0;
    }
    if (flag==0){
        cout<<n+1<<endl;
        A[1] = 1;
        for(ll i = 2;i<=k;i++)A[i] = 0;
        forn(i,k)cout<<A[i];
        for(ll i = k+1;i<=n+1;i++){
            ll g = i%k;
            if (g==0) g = k;
            cout<<A[g];
        }
        cout<<endl;
        return 0;
    }
    cout<<n<<endl;
    A[k]++;
    for(ll i = k;i>=1;i--){
        A[i-1]+=A[i]/10;
        A[i]%=10;
    }
    forn(i,k)cout<<A[i];
    for(ll i = k+1;i<=n;i++){
        ll g = i%k;
        if (g==0) g = k;
        cout<<A[g];
    }
    return 0;
}
// 9 7+2