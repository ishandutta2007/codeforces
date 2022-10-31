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
ll t,n,m;
ll A[DIM],B[DIM];
int main() {
    //freopen("input.txt","r",stdin);
    schnell;
    cin>>t;
    forn(query,t){
        cin>>n;
        ll res = 0,cnt1 = 0,cnt2 = 0;
        forn(i,n){
            ll x; cin>>x;
            if (x%2)cnt1++;
            else cnt2++;
        }
        cin>>m;
        forn(i,m){
            ll x; cin>>x;
            if (x%2)res+=cnt1;
            else res+=cnt2;
        }

        cout<<res<<endl;
    }

}