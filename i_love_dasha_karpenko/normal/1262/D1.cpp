#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 100+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

ll n,m,A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i];
    cin>>m;
    forn(query,m){
        ll k,pos; cin>>k>>pos;
        set<pp> S;
        set<pp> S1;

        for(ll i = n;i>=1;i--){
            S.insert({A[i],i});
            S1.insert({i,A[i]});

            if(S.size()>k){
                ll t = (*S.begin()).fi;
                vector<ll> V;
                for(auto to:S){
                    if (to.fi!=t)break;
                    V.pb(to.sc);
                }
                ll flag = 0;
                for(ll to:V){
                    auto it = S1.lower_bound({to,t});
                    it++;
                    if ((*it).sc<t){
                        S.erase({t,to});
                        S1.erase({to,t});
                        flag = 1;
                        break;
                    }
                }
                if (flag==0){
                    ll to = V.back();
                    S1.erase({to,t});
                    S.erase({t,to});
                }
            }

        }
        vector<pp> ans;
        for(auto to:S){
            ans.pb({to.sc,to.fi});
        }
        sort(ans.begin(),ans.end());
        cout<<ans[pos-1].sc<<endl;
    }
    return 0;
}