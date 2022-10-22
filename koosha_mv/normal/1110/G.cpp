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
 
const int N=5e5+99;

int n,t,ck,ans,cnt[4];
vector<int> g[N];
string s;

void dfs(int x,int h,int par=0){
   if(g[x].size()>3) ans=1;
   if(g[x].size()==3){
      int brg=0;
      if(s[x-1]=='W') ans=1;
      f(i,0,g[x].size())
         if(g[g[x][i]].size()==1)
            brg++;
      if(brg<2)
         ans=1;
      cnt[(h&1)]++;
   }
   if(s[x-1]=='W'){
      int brg=0;
      f(i,0,g[x].size())
         if(g[g[x][i]].size()==1)
            brg++;
      if(g[x].size()>1 && brg!=g[x].size()) ans=1;
      cnt[1-(h&1)]++;
   }
   f(i,0,g[x].size())
      if(g[x][i]!=par){
         if(s[x-1]=='W' && s[g[x][i]-1]=='W' && n>2) ans=1;
         dfs(g[x][i],h+1,x);
      }
}

int main(){
   cin>>t;
   f(q,0,t){
      ans=0;
      cin>>n;
      //if(t==40000 && q==0 && n==1) ck=1;
      f(i,1,n+1)
         g[i].clear();
      f(i,1,n){
         int u,v;
         Gett(u,v);
         g[u].pb(v);
         g[v].pb(u);
         if(ck && q==20) cout<<u<<" "<<v<<endl;
      }
      cin>>s;
      if(ck && q==20) cout<<s<<endl;
      cnt[0]=cnt[1]=0;
      dfs(1,0);
      if(cnt[0]>1 || cnt[1]>1) ans=1;
      if(!ck){
         if(ans) cout<<"White"<<'\n';
         else cout<<"Draw"<<'\n';
      }
   }
}