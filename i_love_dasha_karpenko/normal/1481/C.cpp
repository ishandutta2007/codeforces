#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM],B[DIM],mal[DIM],can[DIM],ans[DIM];
vector<ll> pos[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        for(ll i = 1;i<=n;++i)cin>>A[i];
        for(ll i = 1;i<=n;++i)cin>>B[i];
        ll need = 0;
        for(ll i = 1;i<=n;++i){
            can[B[i]] = i;
            if (A[i]!=B[i]){
                pos[B[i]].push_back(i);
                ++need;
            }
        }
        for(ll i = 1;i<=m;++i)cin>>mal[i];
        if (can[mal[m]]==0){
            cout<<"NO\n";
            for(ll i = 1;i<=max(m,n);++i){
                A[i] = B[i] = mal[i] = can[i] = ans[i] = 0;
                pos[i].clear();
            }
            continue;
        }
        ll junk = 0;
        for(ll i = m;i>=1;--i){
            if (!pos[mal[i]].empty()){
                ans[i] = pos[mal[i]].back();
                if (junk==0)junk = pos[mal[i]].back();
                pos[mal[i]].pop_back();
                --need;
            }
            else if (can[mal[i]]){
                ans[i] = can[mal[i]];
                if (junk==0)junk = can[mal[i]];
            }
            else{
                ans[i] = junk;
            }
        }
        if (need){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(ll i = 1;i<=m;++i)cout<<ans[i]<<' ';
            cout<<endl;
        }
        for(ll i = 1;i<=max(m,n);++i){
            A[i] = B[i] = mal[i] = can[i] = ans[i] = 0;
            pos[i].clear();
        }
    }
    return 0;
}