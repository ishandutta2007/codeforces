#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 400+7;
const ll INF = 10E17;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tc;
    cin>>tc;
    forn(qe,tc){
        string a,b,c;
        cin>>a>>b>>c;
        ll flag = 0;
        for(ll i = 0;i<a.length();i++){
            if ( b[i]==c[i] || a[i]==c[i])continue;
            flag = 1;
            break;
        }
        if (flag==1)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}