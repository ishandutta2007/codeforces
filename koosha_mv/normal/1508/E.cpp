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
 
const int N=3e5+99;

int n,c,st,tt,et,order,a[N],s[N],t[N],e[N];
ll res;
vector<int> g[N];

void kill(){
   cout<<"NO";
   exit(0);
}
void dfs(int u){
   vector<pair<int,int> > v;
   s[u]=++st;
   if(a[c]<a[u]){
      e[u]=++et;
      if(e[u]!=a[u]-a[c]) kill();
   }
   sort(g[u].begin(),g[u].end());
   f(i,0,g[u].size())
      v.pb(mp(a[g[u][i]],g[u][i]));
   sort(v.begin(),v.end());
   f(i,0,v.size())
      dfs(v[i].S);
   t[u]=++tt;
}
void dfs(int u,int h){
   if(a[u]<=a[c]){
      res+=h;
      if(t[u]!=a[u]) kill();
      //cout<<u<<" "<<t[u]<<" "<<a[u]<<endl;
   }
   f(i,0,g[u].size())
      dfs(g[u][i],h+1);
}
int main(){
   cin>>n;
   f(i,1,n+1)
      cin>>a[i];
   f(i,1,n){
      int u,v;
      Gett(u,v);
      g[u].pb(v);
   }
   f(i,1,n+1)
      if(a[i]==a[1]-1)
         c=i;
   if(a[1]==n) c=1;
   while(1){
      int mn=n+1;
      f(j,0,g[c].size())
         if(a[c]<a[g[c][j]])
            minm(mn,a[g[c][j]]);
      if(mn==n+1)
         break;
      f(j,0,g[c].size())
         if(a[g[c][j]]==mn){
            swap(a[c],a[g[c][j]]);
            c=g[c][j];
            break;
         }
      res--;
   }
   dfs(1);
   dfs(1,0);
   cout<<"YES"<<endl;
   cout<<res<<endl;
   f(i,1,n+1)
      cout<<s[i]<<" ";
}