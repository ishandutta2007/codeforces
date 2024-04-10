#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
const ll DIM = 1000000+7;
const ll INF = 10e14;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)
ll n,A[DIM],buf[DIM],res = 0,res1 = 0;
pp ans;
void solve(ll l,ll r){
    if (l==r)return;
    ll tm = (l+r)/2;
    solve(l,tm); solve(tm+1,r);
    ll mx1 = 0,mx2 = 0,p1 = tm+1;
    for(ll i = tm;i>=l;i--){
        mx1 = max(mx1,A[i]);
        while(p1<=r && mx1>=max(A[p1],mx2)){
            mx2 = max(mx2,A[p1]);
            p1++;
        }

       res+=(p1-tm-1)*mx1;
    }
    mx1 = 0; mx2 = 0; p1 = tm;
    for(ll i = tm+1;i<=r;i++){
        mx1 = max(mx1,A[i]);
        while(p1>=l && max(A[p1],mx2)<mx1){
            mx2 = max(mx2,A[p1]);
            p1--;
        }
        res+=(tm-p1)*mx1;
    }
    //merge(A+l,A+tm+1,A+tm+1,A+r+1,buf);
    //copy(buf,buf+r-l+1,A+l);
   // cout<<res<<' '<<l<<' '<<r<<endl;
}
void solve1(ll l,ll r){
    if (l==r)return;
    ll tm = (l+r)/2;
    solve1(l,tm); solve1(tm+1,r);
    ll mx1 = INF,mx2 = INF,p1 = tm+1;
    for(ll i = tm;i>=l;i--){
        mx1 = min(mx1,A[i]);
        while(p1<=r && mx1<=min(A[p1],mx2)){
            mx2 = min(mx2,A[p1]);
            p1++;
        }

       res1+=(p1-tm-1)*mx1;
    }
    mx1 = INF; mx2 = INF; p1 = tm;
    for(ll i = tm+1;i<=r;i++){
        mx1 = min(mx1,A[i]);
        while(p1>=l && min(A[p1],mx2)>mx1){
            mx2 = min(mx2,A[p1]);
            p1--;
        }
        res1+=(tm-p1)*mx1;
    }
    //cout<<l<<' '<<r<<' '<<res1<<endl;
    //merge(A+l,A+tm+1,A+tm+1,A+r+1,buf);
    //copy(buf,buf+r-l+1,A+l);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i];
    solve(1,n);
    solve1(1,n);
    cout<<res-res1<<endl;
    return 0;
}
// 1 2 3
// 3+1 = 4