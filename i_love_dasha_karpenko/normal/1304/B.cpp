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
const ll DIM = 100+7;
const ll INF = 10E17;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
string A[DIM];
map<string,ll> M;
ll vis[DIM];
ll pal(string &s){
    for(ll i = 0;i<s.length()/2;i++){
        if (s[i]!=s[s.length()-i-1])return 0;
    }
    return 1;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<pp> pos;
    vector<ll> pals;
    forn(i,n){
        string s;
        cin>>s;
        A[i] = s;
        string s1 = s;
        reverse(s1.begin(),s1.end());
        if (M.count(s1)==1){
            pos.pb({M[s1],i});
            vis[M[s1]] = 1;
            vis[i] = 1;
            M.erase(s1);
        }
        else{
            M[s] = i;
        }
    }
    ll mid = -1;
    forn(i,n){
        if (vis[i]==0 && pal(A[i])){
            mid = i;
            break;
        }
    }
    vector<ll> V1,V2;
    for(pp to:pos){
        V1.pb(to.fi);
        V2.pb(to.sc);
    }
    reverse(V2.begin(),V2.end());
    if (mid!=-1)V1.pb(mid);
    cout<<(V1.size()+V2.size())*m<<endl;
    for(ll to:V1){
        cout<<A[to];
    }
    for(ll to:V2){
        cout<<A[to];
    }
    cout<<endl;

    return 0;
}