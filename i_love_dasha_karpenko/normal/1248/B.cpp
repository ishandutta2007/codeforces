#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 0;i<n;i++)
#define fi first
#define sc second
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> my_super_set;
const ll DIM = 100007;
const ll INF = 10E16;
bool const operator<(const pp&a,const pp&b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
bool const operator>(const pp&a,const pp&b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi>b.fi;
}
bool const operator==(const pp &a,const pp&b){
    return a.fi==b.fi && a.sc==b.sc;
}
ll A[DIM];
int main() {
    //freopen("input.txt","r",stdin);
    schnell;
    ll n; cin>>n;
    ll r  = 0;
    forn(i,n){
        cin>>A[i];
        r+=A[i];
    }
    sort(A,A+n,greater<ll>());
    ll res = 0;
    forn(i,n/2+n%2){
        res+=A[i];
    }
    r-=res;
    cout<<res*res+r*r<<endl;

}