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
    #define gett(x) scanf("%d",&x);a
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
     
    const int N=2e5+99,M=7;
     
    int n,ans,a[N],mark[N];
    vector<int> v[N],g[N];
    pair<int,int> mx;
     
    void dfs(int x,int dist,int s){
        mark[x]++;
        if(mx<mp(dist,x)) mx=mp(dist,x);
        f(i,0,g[x].size())
            if(mark[g[x][i]]==s)
                dfs(g[x][i],dist+1,s);
    }
    void solve(int x){
        f(i,0,sz(v[x]))
            mark[v[x][i]]=1;
        f(i,0,sz(v[x]))
            if(mark[v[x][i]]==1){
                mx=mp(0,v[x][i]);
                dfs(v[x][i],1,1);
                dfs(mx.S,1,2);
                //cout<<x<<" : "<<mx.F<<endl;
                maxm(ans,mx.F);
            }
        f(i,0,sz(v[x]))
            mark[v[x][i]]=0;
    }
     
    int main(){
        cin>>n;
        f(i,1,n+1){ 
            gett(a[i]);
            for(int j=2;j*j<=a[i];j++){
                if(a[i]%j==0){
                    v[j].pb(i);
                    while(a[i]%j==0)
                        a[i]/=j;
                }
            }
            if(1<a[i]) v[a[i]].pb(i);
        }
        f(i,1,n){
            int u,v;
            Gett(u,v);
            g[u].pb(v);
            g[v].pb(u);
        }
        f(i,2,N)
            solve(i);
        cout<<ans;
    }