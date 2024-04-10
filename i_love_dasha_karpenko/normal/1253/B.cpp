#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 10E5 +7;
const ll INF = 10E17+7;
ll A[DIM],vis[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    vector<ll> ans;
    ll cnt = 0,day = 1,left = 0;
    forn(i,n){
        left++;
        ll x; cin>>x;
        if (x<0)A[-x]--;
        else A[x]++;
        if (A[abs(x)]==0)vis[abs(x)] = day;
        if (A[abs(x)]<0 || A[abs(x)]>=2 || (A[abs(x)]>0 && vis[abs(x)]==day)){
            cout<<-1<<endl;
            return 0;
        }
        if (A[abs(x)]==1)cnt++;
        if (A[abs(x)]==0)cnt--;
        if (cnt==0){
            ans.pb(left);
            left = 0;
            day++;
        }
    }
    if (cnt!=0){
        cout<<"-1\n";
        return 0;
    }
    cout<<ans.size()<<endl;
    for(ll to:ans)cout<<to<<' ';

    return 0;
}

// 1 2 3
//