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
const ll DIM = 2E5+7;
const ll INF = 1e8;
const ll MOD = 1E9+123;

ll F(ll x){
    for(ll i = 2;i<=sqrt(x);++i)if (x%i==0)return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
cin>>s;
ll n = s.length()-1;
cout<<(s[n]-'0')%2<<endl;
}