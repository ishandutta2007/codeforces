#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
const ll DIM = 1000+7;
const ll INF = 10e14;
const ll MOD = 1000000007;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll A[3]; cin>>A[0]>>A[1]>>A[2];
        sort(A,A+3);
        ll dif = A[2]-A[1];
        ll g = min(dif,A[0]);
        A[0]-=g;
        A[2]-=g;
        ll res = g;
        ll h = A[0]/2;
        A[2]-=h;
        A[1]-=A[0]-h;
        res+=A[0];
        res+=min(A[2],A[1]);
        cout<<res<<endl;
    }
    return 0;
}