#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 200007+7;
const ll INF = 10E10;
ll A[DIM],cnt[DIM];
struct node{
    ll s,t,u;
};
map<pp,node > M;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    ll res = 0;
    forn(i,n){
        cin>>A[i];
        res+=A[i];
    }
    ll q; cin>>q;

    forn(i,q){
        ll s,t,u; cin>>s>>t>>u;
        if (M.count({s,t})!=0){
            node e = M[{s,t}];
            if (e.u!=0){
                cnt[e.u]--;
                if (cnt[e.u]<A[e.u])res++;
            }
        }
        if (u==0){cout<<res<<endl;M[{s,t}] = node{s,t,u};continue;}
        M[{s,t}] = node{s,t,u};
        cnt[u]++;
        if (cnt[u]<=A[u])res--;
        cout<<res<<endl;
    }

    return 0;
}