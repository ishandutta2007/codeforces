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
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 5000+7;
const ll INF = 10E17;
pp A[DIM];
ll cnt[DIM],cn[DIM];
vector<ll> G[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        for(ll i = 0;i<=n;++i){
            cnt[i] = 0;
            cn[i] = 0;
            G[i].clear();
        }
        forn(i,n){
            cin>>A[i].fi>>A[i].sc;
            cnt[A[i].fi]++;
            G[A[i].fi].pb(A[i].sc);
        }
        ll pref = cnt[0];
        forn(i,n){
            if (cnt[i]==0)continue;
            ll r = i-pref;
            cn[i] = r;
            pref+=cnt[i];
        }
        priority_queue<ll> Q;
        ll took = 0;
        ll res = 0;
        priority_queue<ll,vector<ll>,greater<ll> > Q1;
        for(ll i = n;i>=1;i--){
            for(ll to:G[i])Q1.push(to);
            if (cn[i]>took){
                //while(Q1.size()>cn[i]-took)Q1.pop();
                while(Q.size()<cn[i]){
                    Q.push(Q1.top());
                    Q1.pop();
                }
            }
            took = max(took,cn[i]);
        }

        while(!Q.empty()){
            res+=Q.top();
            Q.pop();
        }
        cout<<res<<endl;
    }

    return 0;
}