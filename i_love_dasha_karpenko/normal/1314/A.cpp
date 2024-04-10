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
const ll DIM = 2*10E4+7;
const ll INF = 10E17;

ll t[DIM];
pp A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i].fi;
        A[i].sc = i;
    }
    forn(i,n){
        cin>>t[i];
    }
    sort(A+1,A+1+n);
    priority_queue<ll> Q;
    ll sum = 0,res = 0,ls = 0;
    forn(i,n){

        sum+=t[A[i].sc];
        Q.push(t[A[i].sc]);
        if (i<n && A[i].fi==A[i+1].fi){
            continue;
        }
        while(!Q.empty()){
            ll to = Q.top();
            Q.pop();
            res+=sum-to;
            sum-=to;
            A[i].fi++;
            while( !Q.empty() && i<n && A[i+1].fi==A[i].fi){
                Q.push(t[A[i+1].sc]);
                sum+=t[A[i+1].sc];
                i++;
            }
        }
    }
    while(!Q.empty()){
        ll to = Q.top();
        Q.pop();
        res+=sum-to;
        sum-=to;
    }
    cout<<res<<endl;
    return 0;
}