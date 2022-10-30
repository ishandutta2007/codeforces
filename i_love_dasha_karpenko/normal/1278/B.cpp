#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100+7;
const ll INF = 10E16;
map<char,ll> M,M1;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll a,b; cin>>a>>b;
        ll ri = abs(a-b);
        for(ll j= 0;j<=INF;j++){
            ll sum = (j+1)*j/2;
            ll dif = sum-ri;
            if (dif<0)continue;
            if (dif%2==0){
                cout<<j<<endl;
                break;
            }
        }
    }
    return 0;
}

// 1 2 3
//