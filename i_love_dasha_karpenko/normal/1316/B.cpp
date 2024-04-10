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
const ll DIM = 100000+7;
const ll INF = 10E16;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll t;
    cin>>t;
    //t = 1;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;

        string ans = s;
        ll shift = 1;
        for(ll k = 2;k<=n;k++){
            string ss = "";
            ll moves = 0;
            for(ll i = k-1;i<s.length();i++){
                ss+=s[i];
                moves++;
            }
            moves%=2;
            if (moves%2){
                for(ll i = k-2;i>=0;i--){
                    ss+=s[i];
                }
            }
            else{
                for(ll i = 0;i<k-1;i++)ss+=s[i];
            }
            for(ll i = 0;i<n;i++){
                if (ss[i]<ans[i]){
                    shift = k;
                    ans = ss;
                    break;
                }
                else if (ans[i]<ss[i])break;
            }
            //cout<<ss<<endl;
        }
        cout<<ans<<endl<<shift<<endl;
    }
    return 0;
}