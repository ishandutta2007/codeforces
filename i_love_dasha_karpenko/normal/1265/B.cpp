#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
const ll DIM = 200000+7;
const ll INF = 10e16;
ll A[DIM],ans[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        forn(i,n){
            cin>>A[i];
            ans[i] = 0;
        }
        deque<ll> Q;
        set<ll> S;
        forn(i,n){
            if (S.count(A[i])==1){
                for(;1;){
                    ll v = Q.front(); Q.pop_front();
                    S.erase(v);
                    if (v==A[i])break;
                }
            }
            Q.pb(A[i]);
            S.insert(A[i]);
            ll mx = *(S.rbegin());
            if (mx==Q.size())ans[mx] = 1;
        }
        for (;1;){
            if (Q.front()>Q.back()){
                S.erase(Q.front());
                Q.pop_front();
            }
            else{
                S.erase(Q.back());
                Q.pop_back();
            }
            if (S.empty())break;
             ll mx = *(S.rbegin());
            if (mx==Q.size())ans[mx] = 1;
        }
        forn(i,n)cout<<ans[i];
        cout<<endl;
    }

    return 0;

}