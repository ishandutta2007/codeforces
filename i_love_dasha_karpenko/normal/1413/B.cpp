#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 507;
ll PSC[DIM*DIM],PSR[DIM*DIM],ans[DIM][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=m;++j){
                ll x;
                cin>>x;
                PSC[x] = j;
            }
        }
        for(ll i = 1;i<=m;++i){
            for(ll j = 1;j<=n;++j){
                ll x;
                cin>>x;
                PSR[x] = j;
            }
        }
        for(ll i = 1;i<=n*m;++i){
            ans[PSR[i]][PSC[i]] = i;
        }
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=m;++j)cout<<ans[i][j]<<' ';
            cout<<endl;
        }

    }
    return 0;

}