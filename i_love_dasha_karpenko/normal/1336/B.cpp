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
const ll INF = 1e19;


ll a,b,c,A[DIM],B[DIM],C[DIM],res = INF;
void Ch(ll x,ll y,ll z){
    res = min (res,(x-y)*(x-y)+(x-z)*(x-z)+(z-y)*(z-y));
    if (res==1999999982000000114){
        ll r = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        res = INF;
        cin>>a>>b>>c;
        forn(i,a)cin>>A[i];
        forn(i,b)cin>>B[i];
        forn(i,c)cin>>C[i];
        sort(A+1,A+1+a);
        sort(B+1,B+1+b);
        sort(C+1,C+1+c);
        // a-b
        forn(i,a){
            {
                ll b1 = lower_bound(B+1,B+1+b,A[i])-B;
                if (b1<=b){
                    ll mi = min(A[i],B[b1]),mx = max(A[i],B[b1]);
                    ll l = lower_bound(C+1,C+1+c,mi)-C;
                    ll r = lower_bound(C+1,C+1+c,mx)-C;
                    if (l>c)l = c;
                    if (r>c)r = c;
                    while(l!=r){
                        ll tm = (l+r+1)/2;
                        if (mx-C[tm]>C[tm]-mi)l = tm;
                        else r = tm-1;
                    }
                    Ch(mi,mx,C[l]);
                    if (l+1<=c)
                    Ch(mi,mx,C[l+1]);
                }
            }
            {
                ll b1 = lower_bound(B+1,B+1+b,A[i])-B;
                b1--;
                if (b1<=b){
                    if (b1<1)continue;
                    ll mi = min(A[i],B[b1]),mx = max(A[i],B[b1]);
                    ll l = lower_bound(C+1,C+1+c,mi)-C;
                    ll r = lower_bound(C+1,C+1+c,mx)-C;
                    if (l>c)l = c;
                    if (r>c)r = c;
                    while(l!=r){
                        ll tm = (l+r+1)/2;
                        if (mx-C[tm]>C[tm]-mi)l = tm;
                        else r = tm-1;
                    }
                    Ch(mi,mx,C[l]);
                    if (l+1<=c)
                    Ch(mi,mx,C[l+1]);
                }
            }
        }
        // a-c
        forn(i,a){
            {
                ll c1 = lower_bound(C+1,C+1+c,A[i])-C;
                if (c1<=c){
                    ll mi = min(A[i],C[c1]),mx = max(A[i],C[c1]);
                    ll l = lower_bound(B+1,B+1+b,mi)-B;
                    ll r = lower_bound(B+1,B+1+b,mx)-B;
                    if (l>b)l = b;
                    if (r>b)r = b;
                    while(l!=r){
                        ll tm = (l+r+1)/2;
                        if (mx-B[tm]>B[tm]-mi)l = tm;
                        else r = tm-1;
                    }
                    Ch(mi,mx,B[l]);
                    if (l+1<=b)
                    Ch(mi,mx,B[l+1]);
                }
            }
            {
                ll c1 = lower_bound(C+1,C+1+c,A[i])-C;

                c1--;
                if (c1<=c){
                    if (c1<1)continue;
                    ll mi = min(A[i],C[c1]),mx = max(A[i],C[c1]);
                    ll l = lower_bound(B+1,B+1+b,mi)-B;
                    ll r = lower_bound(B+1,B+1+b,mx)-B;
                    if (l>b)l = b;
                    if (r>b)r = b;
                    while(l!=r){
                        ll tm = (l+r+1)/2;
                        if (mx-B[tm]>B[tm]-mi)l = tm;
                        else r = tm-1;
                    }
                    Ch(mi,mx,B[l]);
                    if (l+1<=b)
                    Ch(mi,mx,B[l+1]);
                }
            }
        }
        forn(i,b){
            {
                ll c1 = lower_bound(C+1,C+1+c,B[i])-C;
                if (c1<=c){
                    ll mi = min(B[i],C[c1]),mx = max(B[i],C[c1]);
                    ll l = lower_bound(A+1,A+1+a,mi)-A;
                    ll r = lower_bound(A+1,A+1+a,mx)-A;
                    if (l>a)l = a;
                    if (r>a)r = a;
                    while(l!=r){
                        ll tm = (l+r+1)/2;
                        if (mx-A[tm]>A[tm]-mi)l = tm;
                        else r = tm-1;
                    }
                    Ch(mi,mx,A[l]);
                    if (l+1<=a)
                    Ch(mi,mx,A[l+1]);
                }
            }
            {
                ll c1 = lower_bound(C+1,C+1+c,B[i])-C;
                c1--;
                if (c1<=c){
                    if (c1<1)continue;
                    ll mi = min(B[i],C[c1]),mx = max(B[i],C[c1]);
                    ll l = lower_bound(A+1,A+1+a,mi)-A;
                    ll r = lower_bound(A+1,A+1+a,mx)-A;
                    if (l>a)l = a;
                    if (r>a)r = a;
                    while(l!=r){
                        ll tm = (l+r+1)/2;
                        if (mx-A[tm]>A[tm]-mi)l = tm;
                        else r = tm-1;
                    }
                    Ch(mi,mx,A[l]);
                    if (l+1<=a)
                    Ch(mi,mx,A[l+1]);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}