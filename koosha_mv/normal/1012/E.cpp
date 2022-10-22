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
 
const int N=5e5+99,mod=1e9+7;

int n,s,c,ck,a[N],b[N],p[N],col[N],par[N],mark[N];
vector<vector<int> > ans;
vector<int> v,va[N],vb[N];
map<int,int> Tn;

void check(){
   f(i,1,n+1)
      if(b[p[i]]!=a[i] && (p[i]!=0 || a[i]!=b[i]))
         cout<<"SALAM";
   return ;
}
int Get_par(int u){
   if(par[u]<0) return u;
   return par[u]=Get_par(par[u]);
}
void Swap(int u,int v){
   swap(p[u],p[v]);
   u=Get_par(u),v=Get_par(v);
   if(par[u]>par[v]) swap(u,v);
   par[u]+=par[v];
   par[v]=u;
}
void dfs1(int x,int rt){
   if(x==rt) par[rt]=-1;
   else par[x]=rt,par[rt]--;
   if(p[x]!=rt) dfs1(p[x],rt);
}
void dfs2(int x){
   v.pb(x);
   mark[x]=1;
   if(!mark[p[x]]) dfs2(p[x]);
}
void dfs3(int x){
   mark[x]=1;
   if(!mark[p[x]]) col[p[x]]=col[x],dfs3(p[x]);
}
void read(){
   cin>>n>>s;
   f(i,1,n+1){
      cin>>a[i];
      b[i]=a[i];
   }
   sort(b+1,b+n+1);
   f(i,1,n+1){
      if(b[i]!=b[i-1]){
         Tn[b[i]]=++c;
      }
   }
   f(i,1,n+1){
      a[i]=Tn[a[i]];
      b[i]=Tn[b[i]];
      if(a[i]!=b[i]){
         va[a[i]].pb(i);
         vb[b[i]].pb(i);
         s--;
      }
   }
   f(i,1,n+1)
      f(j,0,va[i].size())
         p[va[i][j]]=vb[i][j];
   f(i,1,n+1){
      if(!par[i] && p[i]){
         dfs1(i,i);
      }
   }
   f(i,1,n+1){
      f(j,1,va[i].size()){
         if(Get_par(va[i][j])!=Get_par(va[i][j-1])){
            Swap(va[i][j-1],va[i][j]);
         }
      }
   }
}
void solve(){
   check();
   if(s<0){
      cout<<-1;
      return ;
   }
   if(s>1){
      vector<int> v,V;
      c=0;
      f(i,1,n+1){
         if(p[i] && !mark[i]){
            col[i]=++c;
            dfs3(i);
         }
      }
      fill(mark,mark+N,0);
      f(i,1,n+1){
         if(p[i] && mark[col[i]]==0 && s){
            mark[col[i]]=1;
            v.pb(i);
            V.pb(p[i]);
            s--;
         }
      }
      if(v.size()>1){
         ans.pb(v);
         f(i,0,v.size()){
            if(i==0) p[v[i]]=V.back();
            else p[v[i]]=V[i-1];
         }
      }
   }
   fill(mark,mark+N,0);
   f(i,1,n+1){
      if(p[i] && !mark[i]){
         v.clear();
         dfs2(i);
         ans.pb(v);
      }
   }
   cout<<ans.size()<<endl;
   f(i,0,ans.size()){
      cout<<ans[i].size()<<endl;
      f(j,0,ans[i].size())
         cout<<ans[i][j]<<" ";
      cout<<endl;
   }
}

int main(){
   read();
   solve();
}