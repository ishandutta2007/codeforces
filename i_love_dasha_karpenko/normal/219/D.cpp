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
ll n, res = 0,mx = INF;
vector<node> A[DIM];
arr V,D;
void dfs(ll x){
    V[x]=1;
    mx = min(mx,D[x]);
    for (int i = 0;i<A[x].size();i++){
        node k = A[x][i];
        if (V[k.sc]==1)continue;
        if (k.m==0)D[k.sc]=D[x]+1;
        else D[k.sc]=D[x]-1;
        dfs(k.sc);
    }
}
void basedfs(ll x){
    V[x]=1;
    for (int i = 0;i<A[x].size();i++){
        node k = A[x][i];
        if (V[k.sc]==1)continue;
        res+=k.m;
        basedfs(k.sc);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ll x,y;
    for (int i = 1;i<n;i++){
        cin>>x>>y;
        A[x].push_back({y,0});
        A[y].push_back({x,1});
    }
    basedfs(1);
    D[1]=res;
    memset(V,0,sizeof(V));
    dfs(1);
    cout<<mx<<endl;
    for (int i = 1;i<=n;i++){
        if (D[i]==mx){
            cout<<i<<' ';
        }
    }
}