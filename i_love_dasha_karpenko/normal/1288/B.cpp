#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 5000+7;
const ll INF = 10E17;
ll to_up(ll x,ll y){
    return x/y+(x%y!=0?1:0);
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(qer,t){
        ll a,b; cin>>a>>b;
        ll cnt1 = 0;
        ll x = b,flag1 = 0;
        while(x>0){
            cnt1++;
            if (x%10!=9)flag1 = 1;
            x/=10;
        }

        //cnt2-=flag2;
        cnt1-=flag1;
        cout<<cnt1*a<<endl;
        //cout<<cnt1<<' '<<cnt2<<endl;
    }
    return 0;
}