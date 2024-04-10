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
const ll DIM = 5000+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n = s.length();
        ll l = 1,r = n+1;
        while(l!=r){
            ll tm = (l+r)/2;
            ll last = 0;
            ll flag = 0;
            for(ll i = 0;i<n;i++){
                if (s[i]=='R' && i-last+1>tm){
                    flag = 1;
                    break;
                }
                else if (s[i]=='R')last = i+1;
            }
            if (n+1-last>tm)flag = 1;
            if (flag==0)r = tm;
            else l = tm+1;
        }
        cout<<l<<endl;
    }
    return 0;
}