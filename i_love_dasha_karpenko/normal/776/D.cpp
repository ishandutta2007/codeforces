#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
typedef vector<ll> tree[DIM];
struct node{
    ll sc,m;
};
ll n,m,flag = 0;
arr P,V,vis;
tree A;
set<ll> S;

void dfs(ll x){
    //cout<<x<<' '<<x-m<<endl;
    if (S.count(x+m)==1 || S.count(x-m)==1)
        flag = 1;
    vis[x]=1;

    S.insert(x);
    for (int i = 0;i<A[x].size();i++){
        ll k = A[x][i];
        if (vis[k]==1)continue;
        dfs(k);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i = 1;i<=n;i++)cin>>P[i];
    for (int i = 1;i<=m;i++){
        ll x,room;
        cin>>x;
        for (int j = 0;j<x;j++){
            cin>>room;
            if (V[room]==0)V[room]=i;
            else{
                if (P[room]==1){
                    A[i].push_back(V[room]);
                    A[V[room]].push_back(i);
                    A[i+m].push_back(V[room]+m);
                    A[V[room]+m].push_back(i+m);
                }
                else{
                    A[i].push_back(V[room]+m);
                    A[V[room]+m].push_back(i);
                    A[V[room]].push_back(i+m);
                    A[i+m].push_back(V[room]);
                }
            }
        }
    }
    for (int i = 1;i<=m*2;i++){
        if (vis[i]==0){
            S.clear();
            dfs(i);
        }
    }
    //cout<<S.size()<<endl;
    if (flag==1){
        cout<<"NO"<<endl;
    }
    else
        cout<<"YES"<<endl;
}