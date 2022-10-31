//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E3+7;
const ll INF = 1E18;
int A[DIM][DIM];
ll dist[DIM][DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,w;
    cin>>n>>m>>w;
    priority_queue<pair<ll,pair<int,int> >, vector<pair<ll,pair<int,int> > >, greater<pair<ll,pair<int,int> > > > Q1;
    vector<pair<ll,pair<ll,ll> > > Q2;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j) {
            cin >> A[i][j];
            if (A[i][j]>0){
                Q2.push_back({A[i][j],{i,j}});
            }
            dist[i][j] = INF;
        }
    }
    sort(Q2.begin(),Q2.end(),greater<pair<ll,pair<ll,ll> > >());
    ll V = INF;

   // memset(dist,-1,sizeof(dist));
    dist[1][1] = 0;
    Q1.push({0,{1,1}});
    while(!Q1.empty() || !Q2.empty()){
        pair<ll,pair<ll,ll> > t;
        if (Q1.empty()){
            t = Q2.back();

            dist[t.second.first][t.second.second] = min(dist[t.second.first][t.second.second],t.first+V);
            t.first+=V;
            Q2.pop_back();
        }
        else if (Q2.empty()){
            t = Q1.top();

            Q1.pop();
        }
        else{
            if (Q1.top().first<Q2.back().first+V){
                t = Q1.top();

                Q1.pop();
            }
            else{
                t = Q2.back();
                dist[t.second.first][t.second.second] = min(dist[t.second.first][t.second.second],t.first+V);
                t.first+=V;
                Q2.pop_back();
            }
        }
        ll x = t.second.first,y = t.second.second,dd = t.first;
        if (dist[x][y]<dd)
            continue;
        if (A[x][y])
            V = min(V,dist[x][y]+A[x][y]);
        for(ll dx = -1;dx<=1;++dx){
            ll dy = 0;
            if (x+dx>=1 && x+dx<=n && y+dy>=1 && y+dy<=m && A[x+dx][y+dy]!=-1 && dist[x+dx][y+dy]>dist[x][y]+w && (A[x+dx][y+dy]==0?INF:A[x+dx][y+dy])+V>dist[x][y]+w){
                dist[x+dx][y+dy] = dist[x][y]+w;
                Q1.push({dist[x+dx][y+dy],{x+dx,y+dy}});
            }

        }
        for(ll dy = -1;dy<=1;++dy){
            ll dx = 0;
            if (x+dx>=1 && x+dx<=n && y+dy>=1 && y+dy<=m && A[x+dx][y+dy]!=-1 && dist[x+dx][y+dy]>dist[x][y]+w && (A[x+dx][y+dy]==0?INF:A[x+dx][y+dy])+V>dist[x][y]+w){
                dist[x+dx][y+dy] = dist[x][y]+w;
                Q1.push({dist[x+dx][y+dy],{x+dx,y+dy}});
            }

        }
    }
    if (dist[n][m]>=INF)
        cout<<-1<<endl;
    else cout<<dist[n][m]<<endl;
    return 0;
}