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
const ll DIM = 3*10E4+7;
const ll INF = 10E17;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        string s;
        cin>>s;
        ll cnt = 0,l = -1,r = -2;
        for(ll i = 0;i<s.length();i++){
            if (s[i]=='1'){
                cnt++;
                if (l==-1)l = i;
                r = i;
            }
        }
        cout<<r-l+1-cnt<<endl;
    }
    return 0;
}