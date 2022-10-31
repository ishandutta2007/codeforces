#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 3500 +7;
const ll INF = 10E17;

ll A[DIM],beg[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n,m,k;
        cin>>n>>m>>k;

        m--;
        forn(i,n){
            cin>>A[i];
        }
        if (m==0){
            cout<<max(A[1],A[n])<<endl;
            continue;
        }

        forn(i,m+1){
            beg[i] = max(A[i],A[n+i-m-1]);
        }
        if (k>=m){
            ll res = 0;
            forn(i,m+1){
                res = max(res,beg[i]);
            }
            cout<<res<<endl;
            continue;
        }

        queue<ll> Q;
        set<pp> S;
        ll res = 0;
        forn(i,m+1){
            Q.push(i);
            S.insert({beg[i],i});
            while(Q.size()>m+1-k){
                ll g = Q.front();
                Q.pop();
                S.erase({beg[g],g});
            }
            if (Q.size()==m+1-k)
            res = max(res,S.begin()->fi);
        }
        cout<<res<<endl;
    }
    return 0;
}