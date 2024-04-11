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
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
     
const int N=3e5+99;
     
int n,k,T,b[N],par[N],Add[N],sum[N];
pair<int,int> a[N];
unordered_map<int,int> m[N];
ll ans;
 
int Mod(int x){
    while(k<=x) x-=k;
    return x;
}
int Get_par(int u){
    if(par[u]<0) return u;
    if(par[u]==0) return 0;
    return par[u]=Get_par(par[u]);    
}
void merge1(int u,int v){ // chap>>rast
    if(!u || !v) return ;
    Add[v]=Mod(Add[v]+sum[u]);
    for(auto X:m[u]){
        pair<int,int> x=X;
        x.F+=Add[u];
        x.F=Mod(x.F+k-Add[v]);
        m[v][x.F]+=x.S;
    }
    sum[v]=Mod(sum[v]+sum[u]);
    par[v]+=par[u];
    par[u]=v;
}
void merge2(int u,int v){// rast>>cahp
    if(!u || !v) return ;
    for(auto X:m[v]){
        pair<int,int> x=X;
        x.F=Mod(x.F+Add[v]+sum[u]+k-Add[u]);
        m[u][x.F]+=x.S;
    }
    sum[u]=Mod(sum[u]+sum[v]);
    par[u]+=par[v];
    par[v]=u;
}
void add(int x){
    par[x]=-1;
    sum[x]=b[x]%k;
    int u=Get_par(x-1),v=Get_par(x+1);
    if(par[v]<par[u]){// chap>>rast
        for(auto X:m[u]){
            pair<int,int> x=X;
            x.F=Mod(x.F+Add[u]);
            x.F=Mod(sum[u]-x.F+k);
            if(x.F==0 && x.S){ ans+=x.S-1; }
            ans+=1ll*x.S*m[v][Mod(k+k-x.F-Add[v])];
            if(m[v][Mod(k+k-x.F-Add[v])]==0){
                   m[v].erase((k+k-x.F-Add[v])%k);
            }
        }
        ans+=m[v][Mod(k+k-sum[u]-Add[v])]+(u && sum[u]%k==0);
        if(m[v][Mod(k+k-sum[u]-Add[v])]==0) m[v].erase(Mod(k+k-sum[u]-Add[v]));
 
        m[x][b[x]%k]=1;
        merge2(u,x);
        merge1(Get_par(x),v);
    }
    else{ // rast>>chap
        for(auto X:m[v]){
            pair<int,int> x=X;
            x.F=Mod(x.F+Add[v]);
            ans+=1ll*x.S*m[u][Mod(k+k+sum[u]+x.F-Add[u])];
            if(m[u][Mod(k+k+sum[u]+x.F-Add[u])]==0)
                m[u].erase(Mod(k+k+sum[u]+x.F-Add[u]));
        }
            
        ans+=m[v][(k+k-Add[v]-sum[u])%k];
        if(u) ans+=m[u][(sum[u]+k-Add[u])%k]+(sum[u]%k==0)-1;
        if(m[v][(k+k-Add[v]-sum[u])%k]==0) m[v].erase(Mod(k+k-Add[v]-sum[u]));
        if(m[u][Mod(sum[u]+k-Add[u])]==0) m[v].erase(Mod(sum[u]+k-Add[u]));
 
        m[x][b[x]%k]=1;
        merge1(x,v);
        merge2(u,Get_par(x));
    }
}
     
int main(){
    cin>>n>>k;
    f(i,1,n+1){
        gett(a[i].F);
        b[i]=a[i].F;
        a[i].S=i;
    }
    sort(a+1,a+1+n);
    f(i,1,n+1){
        add(a[i].S);
    }
    cout<<ans;
}