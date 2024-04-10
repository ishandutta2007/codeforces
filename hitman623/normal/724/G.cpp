#include <bits/stdc++.h>

#define int         unsigned long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,d[200005],vis[200005],zero[62],one[62],flag[62];
vii a[200005];
vi vector_space,basis;
void dfs(int node,int par,int x){
    vis[node]=1;
    d[node]=x;
    rep(i,0,62){
        if((1LL<<i)&x) one[i]++;
        else zero[i]++;
    }
    for(auto i:a[node]){
        if(i.x==par) continue;
        if(!vis[i.x]) dfs(i.x,node,x^i.y);
        else vector_space.pb((x^i.y)^d[i.x]);
    }
}
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void find_basis(){
    for(auto x:vector_space){
        for(auto y:basis)
            x=min(x,x^y);
        if(x>0)
            basis.pb(x);
    }
    for(auto i:basis){
        rep(j,0,62){
            if((1LL<<j)&i) flag[j]=1;
        }
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].pb({y,z});
        a[y].pb({x,z});
    }
    int ans=0;
    rep(i,1,n+1){
        if(!vis[i]){
            vector_space.clear();
            basis.clear();
            memset(zero,0,sizeof zero);
            memset(one,0,sizeof one);
            memset(flag,0,sizeof flag);
            dfs(i,-1,0);
            find_basis();
            int r=sz(basis);
            rep(j,0,62){
                int v1=(zero[j]*(zero[j]-1)/2+one[j]*(one[j]-1)/2)%hell;
                int v2=(zero[j]*one[j])%hell;
                if(flag[j]){
                    ans=(ans+expo(2,j+r-1,hell)*(v1+v2))%hell;
                }
                else{
                    ans=(ans+expo(2,r+j,hell)*v2)%hell;
                }
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}