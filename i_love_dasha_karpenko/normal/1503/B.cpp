//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
//#define endl '\n'
#define time fdgfdgdf
const ll DIM = 2E5+7;
const ll INF = 1E18;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    vector<pair<ll,ll> > V[2];
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=n;++j){
            V[(i+j)%2].push_back({i,j});
        }
    }
    for(ll step = 0;step<n*n;++step){
        ll a;
        cin>>a;
        if (a==1){
            if (V[1].empty()){
                cout<<3<<' '<<V[0].back().first<<' '<<V[0].back().second<<endl;
                V[0].pop_back();
            }
            else{
                cout<<2<<' '<<V[1].back().first<<' '<<V[1].back().second<<endl;
                V[1].pop_back();
            }
        }
        if (a==2){
            if (V[0].empty()){
                cout<<3<<' '<<V[1].back().first<<' '<<V[1].back().second<<endl;
                V[1].pop_back();
            }
            else{
                cout<<1<<' '<<V[0].back().first<<' '<<V[0].back().second<<endl;
                V[0].pop_back();
            }
        }
        if (a==3){
            if (V[0].empty()){
                cout<<2<<' '<<V[1].back().first<<' '<<V[1].back().second<<endl;
                V[1].pop_back();
            }
            else{
                cout<<1<<' '<<V[0].back().first<<' '<<V[0].back().second<<endl;
                V[0].pop_back();
            }
        }
    }
    return 0;
}