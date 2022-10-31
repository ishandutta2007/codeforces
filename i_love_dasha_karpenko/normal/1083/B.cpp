#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 3*10E4 +7;
const ll INF = 10E17;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;

    ll r1 = 0,r2 = 0;
    ll res = 0;
    ll flag = 0;
    for(ll i = 0;i<n;i++){
        if (flag==0){
            r1*=2;
            r2*=2;
            r1+=s[i]-'a';
            r2+=t[i]-'a';
            r2-=r1;
            r1 = 0;
            if (r2+1>k){
                flag = 1;
            }
        }
        if (flag==1)res+=k;
        else
        res +=r2+1;
    }
    cout<<res<<endl;
    return 0;
}