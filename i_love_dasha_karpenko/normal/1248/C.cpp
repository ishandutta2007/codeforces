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
ll n,m,fib[DIM];
int main() {
    //freopen("input.txt","r",stdin);
    schnell;
    /*for(ll i = 0;i<po(4);i++){
        ll last = -1;
        ll x = i,flag = 0,r = 0;
        while(x>0){
            if (last==x%2 && flag==1){
                r = 1;
                break;
            }
            if (last==x%2)flag = 1;
            else flag = 0;
            last = x%2;
            x/=2;
        }
        if (r==0){
            ll x= i;
            while(x>0){
                cout<<x%2;
                x/=2;
            }
            cout<<endl;
        }
    }*/
    fib[0] = fib[1] = 2;
    cin>>n>>m;
    ll MOD = 1000000007;
    ll f1 = 2,f2 = 2,f = 0;
    for(ll i = 2;i<=max(m,n);i++){
        fib[i] = fib[i-1]+fib[i-2];
        fib[i]%=MOD;
    }
    ll res = fib[n];
    forn(i,m-1){
        res+=fib[i];
        res%=MOD;
    }
    cout<<res<<endl;
}