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
const ll DIM = 1000+7;
const ll INF = 1e18;

ll ans[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a,b,m;
        cin>>a>>b>>m;
        ll sum = a;
        ll cnt = 1;
        ll power = 1;
        while(sum*2+1<=b){
            sum*=2;
            sum++;
            cnt++;
        }
        if (a==b){
            cout<<"1 "<<a<<endl;
            continue;
        }
        if (b-a<=m){
            cout<<"2 "<<a<<' '<<b<<endl;
            continue;
        }
        if (cnt==1){
            cout<<"-1\n";
            continue;
        }
        forn(i,cnt-2)power*=2;
        ll dif = b-sum-1;
        if (dif<0){
            cout<<"-1\n";
            continue;
        }
        ll n = cnt;
        cnt = 2;
        while(cnt<=n){
            ll g = dif/power;
            g = min(g,m-1);
            ans[cnt++] = g+1;
            dif-=g*power;
            power/=2;
        }
        if (dif>=m){
            cout<<"-1\n";
            continue;
        }
        cout<<n+1<<' '<<a<<' ';
        sum = a;
        for(ll i  = 2;i<=n;i++){
            cout<<sum+ans[i]<<' ';
            sum*=2;
            sum+=ans[i];
        }
        cout<<b<<' ';
        cout<<endl;
    }
    return 0;
}