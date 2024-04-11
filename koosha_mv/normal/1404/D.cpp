#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;

ll ans;
int n,mark[N],vis[N];
vector<int> v[N];
set<pair<int,pair<int,int> > > g[N];

void dfs(int x){
    vis[x]=1;
    if(sz(g[x])){
        pair<int,pair<int,int> > u=*g[x].begin();
        g[x].erase(u);
        g[u.F].erase(mp(x,mp(u.S.S,u.S.F)));
        mark[u.S.S]=1;
        // //cout<<x<<" "<<u.F<<" "<<u.S<<endl;
        dfs(u.F);
    }
}

int main(){
    cin>>n;
    if(n%2==0){
        cout<<"First"<<endl;
        f(i,1,n+1) cout<<i<<" ";
        f(i,1,n+1) cout<<i<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"Second"<<endl;
    f(i,1,2*n+1){
        int x;
        gett(x);
        v[x].pb(i);
    }
    f(i,1,n+1){
        g[v[i][0]%n].insert(mp(v[i][1]%n,mp(v[i][0],v[i][1])));
        g[v[i][1]%n].insert(mp(v[i][0]%n,mp(v[i][1],v[i][0])));
    }
    f(i,0,n)
        if(!vis[i])
            dfs(i);
    f(i,1,2*n+1)
        if(mark[i])
            ans+=i;
    if(ans%(2*n)==0){
        f(i,1,2*n+1)
            if(mark[i]) cout<<i<<" ";
    }
    else
        f(i,1,2*n+1)
            if(!mark[i]) cout<<i<<" ";
    cout<<endl;    
}