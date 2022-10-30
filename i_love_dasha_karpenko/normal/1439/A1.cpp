#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

vector<pair<ll,ll> >ans;
const ll DIM = 107;
ll A[DIM][DIM];
void solve(ll x,ll y){
    vector<pair<ll,ll> > V1,V2;
    for(ll i = x;i<x+2;++i){
        for(ll j = y;j<y+2;++j){
            if (A[i][j]==1)V1.push_back({i,j});
            else V2.push_back({i,j});
        }
    }
    if (V1.size()==0)return;
    while(V1.size()!=0){
        if (V1.size()<3){
            ans.push_back(V1[0]);
            ans.push_back(V2[0]);
            ans.push_back(V2[1]);
            for(ll i = ans.size()-3;i<ans.size();++i){
                A[ans[i].first][ans[i].second]^=1;
            }
        }
        else if (V1.size()>3){
            ans.push_back(V1[0]);
            ans.push_back(V1[2]);
            ans.push_back(V1[1]);
            for(ll i = ans.size()-3;i<ans.size();++i){
                A[ans[i].first][ans[i].second]^=1;
            }
        }
        else{
            ans.push_back(V1[0]);
            ans.push_back(V1[2]);
            ans.push_back(V1[1]);
            for(ll i = ans.size()-3;i<ans.size();++i){
                A[ans[i].first][ans[i].second]^=1;
            }
        }
        V1.clear();
        V2.clear();
        for(ll i = x;i<x+2;++i){
            for(ll j = y;j<y+2;++j){
                if (A[i][j]==1)V1.push_back({i,j});
                else V2.push_back({i,j});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i = 1;i<=n;++i){
            for(ll j=  1;j<=m;++j){
                char ch;
                cin>>ch;
                A[i][j] = ch-'0';
            }
        }
        for(ll i = 1;i+1<=n;i+=2){
            for(ll j = 1;j+1<=m;j+=2){
                solve(i,j);
            }
        }
        if (n%2!=0){
            for(ll j = 1;j+1<=m;j+=2)
                solve(n-1,j);
        }
        if (m%2!=0){
            for(ll i = 1;i+1<=n;i+=2)solve(i,m-1);
        }
        if (n%2 && m%2){
            solve(n-1,m-1);
        }
        cout<<ans.size()/3<<endl;
        for(auto to:ans)cout<<to.first<<' '<<to.second<<endl;
        ans.clear();
    }
    return 0;
}