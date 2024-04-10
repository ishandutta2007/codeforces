#include<bits/stdc++.h>
#define mod 1000000007
//#define mod 998244353
#define N 1000001
#define ll long long int
#define pr pair<ll,ll>
#define ff first
#define ss second
#define pub push_back
#define pob pop_back
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define r(i,a,b) for(ll i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof(a))
#define line cout<<'\n'
#define all(v) v.begin(),v.end()
#define rev(s) reverse(all(s))
#define PI 3.14159265
using namespace std;
 
 
ll BIT[N];
 
void update(ll x,ll val,ll n){
    while(x<=n){
        BIT[x] += val;
        x += x&-x;
    }
}
 
ll query(ll x){
    ll sum = 0;
    while(x>0){
        sum += BIT[x];
        x -= x&-x;
    }
    return sum;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt = 1;
    //cin>>tt;
    f(t,1,tt){
        ll n; cin>>n;
        ll q; cin>>q;
        f(i,1,n){
            ll x; cin>>x;
            update(x,1,n);
        }
        ll l,r;
        f(i,1,q){
            ll k; cin>>k;
            if(k>0) update(k,1,n);
            else{
                k = abs(k);
                l = 1;
                r = n;
                ll x;
                while(l<r){
                    ll mid = (l + r)/2;
                    ll val = query(mid);
                    if(val<k) l = mid + 1;
                    else r = mid;
                }
                update(l,-1,n);
            }
        }
        ll ans;
        bool bl = 0;
        f(i,1,n){
            ll val = query(i);
            if(val>0){
                bl = 1;
                ans = i;
                break;
            }
        }
        if(bl) cout<<ans;
        else cout<<"0";
    }
    return 0;
}