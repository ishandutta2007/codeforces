    #include <bits/stdc++.h>
    using namespace std;
    #define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
    #define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
    #define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
    #define eror(x) cout<<#x<<'='<<(x)<<endl;
    #define f_(i,a,b) for(int i=a;i>=b;i--)
    #define Gett(x,y) scanf("%d%d",&x,&y);
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define get(x) scanf("%I64d",&x);
    #define All(x) x.begin(),x.end()
    #define gett(x) scanf("%d",&x);
    #define Add(x,y) x=(x+y)%mod
    #define maxm(a,b) a=max(a,b)
    #define minm(a,b) a=min(a,b)
    #define lst(x) x[x.size()-1]
    #define sz(x) int(x.size())
    #define mp make_pair
    #define ll long long
    #define pb push_back
    #define S second
    #define F first
     
    const int N=4e5+9,M=2e5+2,mod=1e9+7;
     
    int n,t,res,ans=1,b[N],mark[N];
    pair<int,int> a[N];
    map<int,int> tn;
    vector<int> g[N];
    bool chk;
     
    ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
     
    void read(){
        cin>>n;
        f(i,0,n){
            Gett(a[i].F,a[i].S);
            b[i*2]=a[i].F,b[i*2+1]=a[i].S;
        }
        int c=1;
        sort(b,b+n+n);
        f(i,0,2*n)
            if(!i || b[i]!=b[i-1])
                tn[b[i]]=c++;
        f(i,0,n){
            int u=tn[a[i].F],v=tn[a[i].S]+M;
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    void dfs(int x,int par){
        mark[x]=1;
        t++;
        f(i,0,g[x].size())
            if(mark[g[x][i]] && g[x][i]!=par)
                chk=1;
        f(i,0,g[x].size())
            if(!mark[g[x][i]])
                dfs(g[x][i],x);
    }
     
    int main(){
        read();
        f(i,1,N)
            if(!mark[i]){
                chk=0;
                t=0;
                dfs(i,0);
                res=pow(2,t,mod);
                if(!chk) Add(res,mod-1);
                ans=1ll*ans*res%mod;
            }
        cout<<ans;
    }