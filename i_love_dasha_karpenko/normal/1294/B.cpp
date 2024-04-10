#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 1000+7;
const ll INF = 10E17;

pp A[DIM];
void add(string &s,ll range,char ch){
    forn(i,range)s+=ch;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    A[0] = {0,0};
    forn(qi,t){
        ll n; cin>>n;
        forn(i,n)cin>>A[i].sc>>A[i].fi;
        sort(A+1,A+1+n);
        string ans = "";
        ll flag = 0;
        forn(i,n){
            if (A[i].fi<A[i-1].fi || A[i].sc<A[i-1].sc){
                flag = 1;
                break;
            }
            add(ans,A[i].sc-A[i-1].sc,'R');
            add(ans,A[i].fi-A[i-1].fi,'U');
        }
        if (flag==1)cout<<"NO\n";
        else cout<<"YES\n"<<ans<<endl;
    }
    return 0;
}