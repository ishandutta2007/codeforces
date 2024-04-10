#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 100+7;

vector<ll> V[DIM];
vector<ll> ans[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        typedef pair<ll,pair<ll,ll> > pp;
        set<pp> S;
        set<pair<ll,ll> > del;
        for(ll i = 1;i<=n;++i){
            V[i].resize(m);
            for(ll j = 0;j<m;++j){
                cin>>V[i][j];
            }
            sort(V[i].begin(),V[i].end());
            for(ll j = 0;j<m;++j){
                S.insert({V[i][j],{i,j}});
            }
        }
        ll res = 0;
        while(!S.empty()){
            pair<ll,ll> pos = S.begin()->second;
            ll val = S.begin()->first;
            S.erase(S.begin());
            if (del.count(pos))
                continue;
            res+=val;
            for(ll i = 1;i<=n;++i){
                if (i==pos.first) {
                    ans[i].push_back(V[i][pos.second]);
                    continue;
                }
                while(!V[i].empty() && del.count({i,V[i].size()-1}))
                    V[i].pop_back();
                del.insert({i,V[i].size()-1});
                ans[i].push_back(V[i].back());
                V[i].pop_back();
            }
        }
        for(ll i = 1;i<=n;++i){
            for(auto to:ans[i])
                cout<<to<<' ';
            cout<<endl;
            ans[i].clear();
        }

    }

    return 0;
}