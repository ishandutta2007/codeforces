#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
#define For(i,n) for(int i=0;i<n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define F first
#define S second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MaxN=300500;
int arr[MaxN],dp[MaxN][2],ans=0;
mii cost;
vi adj[MaxN];



void dfs(int nod,int par,int n){
    vi temp;
    for (auto x:adj[nod]){
        if (x==par) continue;
        dfs(x,nod,n);
        ans=max(ans,dp[x][0]);
        ans=max(ans,dp[x][1]);
        temp.push_back(dp[x][0]-cost[x*n+nod]);
    }
    sort(temp.begin(),temp.end());
    if (temp.size()==0 || temp.back()<=0){
        dp[nod][0]=dp[nod][1]=arr[nod];
    }
    else{
        dp[nod][0]=temp.back()+arr[nod];
        dp[nod][1]=dp[nod][0];
        temp.pop_back();
        if (temp.size()==0 || temp.back()<=0){
            ans=max(dp[nod][0],ans);
        }
        else{
            dp[nod][1]+=temp.back();
        }
    }
    
    
    ans=max(ans,dp[nod][0]);
    ans=max(ans,dp[nod][1]);
    
    
}


signed main(){
    int n,u,v,w;
    cin>>n;
    For(i,n) cin>>arr[i];
    For(i,n-1){
        cin>>u>>v>>w;
        u--;
        v--;
        cost[u*n+v]=w;
        cost[v*n+u]=w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0,n);
    cout<<ans<<endl;
}