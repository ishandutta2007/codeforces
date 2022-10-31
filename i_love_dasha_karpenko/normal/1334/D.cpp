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
const ll DIM = 80+7;
const ll INF = 1e18;
ll bin(ll n,ll pos){
    ll sum = (n-1)*n+1;
    ll l = 1,r = n-1;
    while(l!=r){
        ll tm = (l+r+1)/2;
        ll p = sum-(n-tm)*(n-tm+1)-(tm==n);
        if (p<=pos)l = tm;
        else r = tm-1;
    }
    if (sum==l)return 1;
    return l;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        if (l==n*(n-1)+1){
            cout<<1<<endl;
            continue;
        }
        ll st = bin(n,l);
        ll pos = (n-1)*n-(n-st)*(n-st+1)+1-(st==n);

        ll dif = l-pos;
        ll cur = dif/2+st;

        if (dif%2!=0){
            if (st==n)cur = 0;
            cout<<++cur<<' ';
            if (cur>=n){
                st++;
                cur = st;
                if (st==n){
                    st = 1;
                    cur = 0;
                }
            }
            l++;
        }
        ll turn = 0;


        if (l>r)continue;
        while(1){
            if (turn==0)
            cout<<st<<' ';
            else cout<<++cur<<' ';
            turn^=1;
            if (cur>=n){
                st++;
                cur = st;
                if (st==n){
                    st = 1;
                    cur = 0;
                }
            }
            if (l==r)break;
            ++l;
        }
        cout<<endl;
    }
    return 0;
}