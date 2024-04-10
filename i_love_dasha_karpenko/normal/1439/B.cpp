#include <bits/stdc++.h>
using namespace std;
typedef long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

const ll DIM = 1E5+7;
vector<ll> G[DIM];
ll cnt[DIM],vis[DIM];
ll n,m,k;
set<pair<ll,ll> > edges;
void clearall(){
    for(ll i = 1;i<=n;++i){
        cnt[i] = 0;
        G[i].clear();
        vis[i] = 0;
    }
    edges.clear();
}
vector<ll> ans;
ll mm[DIM],ff[DIM];

ll Check(ll v){
    if (k<50){
        if (cnt[v]<k-1)return 0;
        for(ll to:G[v]){
            if(vis[to]==0)ff[to] = 1;
        }
        vector<ll> V;
        for(ll to:G[v]){

            if (ff[to]){
                V.push_back(to);
            }
        }
        ll fl = 0;
        for(ll u:V){
            for(ll v:V){
                if (u>=v)continue;
                if (!edges.count({u,v})){
                    fl = 1;
                    break;
                }
            }
        }

        for(ll to:G[v]){

            mm[to] = 0;
            ff[to] = 0;
        }

        return (fl==0);
    }
    else{
        if (cnt[v]<k-1)return 0;
        for(ll to:G[v]){
            if(vis[to]==0)ff[to] = 1;
        }
        for(ll to:G[v]){

            if (ff[to]){
                for(ll tt:G[to]){
                    if (ff[tt])
                    mm[tt]++;
                }
                mm[to]++;
            }
        }
        ll fl = 0;
        for(ll to:G[v]){
            if (ff[to] && mm[to]!=k-1)fl = 1;
            mm[to] = 0;
            ff[to] = 0;
        }

        return (fl==0);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>m>>k;
        set<pair<ll,ll> > S;
        for(ll i = 1;i<=m;++i){
            ll u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            cnt[v]++;
            cnt[u]++;
            edges.insert({min(u,v),max(u,v)});
        }
        for(ll i = 1;i<=n;++i){
            S.insert({cnt[i],i});
        }
        while(!S.empty()){
            ll v = S.begin()->second;
            if (cnt[v]>=k)break;
            S.erase(S.begin());
            vis[v] = 1;
            for(ll to:G[v]){
                if (vis[to])continue;
                S.erase({cnt[to],to});
                cnt[to]--;
                S.insert({cnt[to],to});
            }
        }
        if (!S.empty()){

            cout<<"1 "<<S.size()<<endl;;
            for(auto to:S)cout<<to.second<<' ';
            cout<<endl;
            clearall();
            continue;
        }
        for(ll i = 1;i<=n;++i){
            cnt[i] = G[i].size();
            vis[i] = 0;
            S.insert({cnt[i],i});
        }

        ll flag =0;
        while(!S.empty()){
            ll v = S.begin()->second;

            if (!Check(v)){
                S.erase(S.begin());
                vis[v] = 1;
                for(ll to:G[v]){
                    if (vis[to]==0){
                        S.erase({cnt[to],to});
                        --cnt[to];
                        S.insert({cnt[to],to});
                    }
                }
            }
            else{
                cout<<"2\n";
                cout<<v<<' ';
                for(ll to:G[v]){
                    if (vis[to]==0)
                    cout<<to<<' ';
                }
                cout<<endl;
                flag = 1;
                break;
            }
        }
        if (flag){
            clearall();
        }
        else{
            cout<<"-1\n";
            clearall();
        }


    }

    return 0;
}