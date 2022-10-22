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

const int N=3e5+99,M=80,mod=998244353;

int n,m,t,u,x,n1,res,ans,li[N],ri[N],mv[N],mark[N],sc[M][N];
vector<pair<int,int> > edge;
vector<int> v,vl;

ll fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){if(k>n) return 0; return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

void make_sc(){
    f(i,0,M){
        sc[i][0]=1;
        f(j,1,n+1){
            sc[i][j]=sc[i][j-1];
            if(i<=j) Add(sc[i][j],C(j-i,mv[j]-i));
        }
    }
}
int solve(int mask){
    int l=0,r=n;
    n1=0;
    vl=v;
    t=0;
    v.clear();
    f(i,0,m)
        if(mask&(1<<i)){
            n1++;
            u=edge[i].F,x=edge[i].S;
            if(!mark[u]) mark[u]=1,t++,v.pb(u);
            if(!mark[x]) mark[x]=1,t++,v.pb(x);
        }
    f(i,0,m)
        if(mask&(1<<i)){
            u=edge[i].F,x=edge[i].S;
            mark[u]=0;
            mark[x]=0;
        }
    f(i,0,v.size()){
        maxm(l,li[v[i]]);
        minm(r,ri[v[i]]);
    }
    res=0;
    if(l<=r){ 
        res=sc[t][r];
        if(l) Add(res,mod-sc[t][l-1]);
    }
}
void calc(){
    int t,ans=0;
    f(mask,0,(1<<sz(edge))){
        solve(mask);
        if(n1&1) Add(ans,mod-res);
        else Add(ans,res);
    }
    Add(ans,mod-1);
    cout<<ans;
}


int main(){
    make_fac();
    cin>>n>>m;
    f(i,1,n+1){
        Gett(li[i],ri[i]);
        mv[li[i]]++;
        mv[ri[i]+1]--;
    }
    f(i,1,n+1)
        mv[i]+=mv[i-1];
    make_sc();
    f(i,0,m){
        Gett(u,x);
        edge.pb(mp(u,x));
    }
    calc();
}