#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2*10E4+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 1000000000;

ll A[DIM];
map<ll,ll> M;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(query,t){
        ll n; cin>>n;
        forn(i,n)cin>>A[i];
        ll l = -1,r,flag=0;
        forn(i,n-1){
            if (abs(A[i]-A[i+1])>=2){
                flag = 1;
                l = i; r = i+1;
                break;
            }
        }
        if (flag==1){
            cout<<"YES\n"<<l<<' '<<r<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;

}