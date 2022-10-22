#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9;

int n,m,a[N],b[N],par[N],last[N];
vector<pair<int,pair<int,int> > > v;
ll ans;

int Get_par(int u){
    return (par[u]<0 ? u : par[u]=Get_par(par[u]));
}
void merge(int u,int v){
  //  cout<<u<<" "<<v<<endl;
    if(v==-1 || (u=Get_par(u))==(v=Get_par(v))) return;
    if(par[v]<par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}

int main(){
    fill(par,par+N,-1);
    fill(last,last+N,-1);
    cin>>m>>n;
    f(i,0,m) gett(a[i]);
    f(i,0,n) gett(b[i]);
    f(i,0,m){
        int s,x;
        gett(s);
        f(j,0,s){
            gett(x);
            x--;
            v.pb(mp(a[i]+b[x],mp(i,x)));
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    f(i,0,sz(v)){
        if(last[v[i].S.F]==-1 || Get_par(v[i].S.S)!=Get_par(last[v[i].S.F])) merge(v[i].S.S,last[v[i].S.F]);
        else ans+=v[i].F;
        last[v[i].S.F]=v[i].S.S;
    }
    cout<<ans;
}