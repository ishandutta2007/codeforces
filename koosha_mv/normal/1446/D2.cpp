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
 
const int N=2e5+9;

int n,k,m,mx,ans,a[N],mark[2*N];
pair<int,int> b[N];
vector<int> v[N];

void solve(int x){
   v[x].pb(n+1),k=0;
   int t=N,sz=v[x].size();
   f(i,0,v[x].size()){
      int last=(i==0 ? 0 : v[x][i-1]);
      int l=upper_bound(v[m].begin(),v[m].end(),last)-v[m].begin();
      int r=upper_bound(v[m].begin(),v[m].end(),v[x][i])-v[m].begin();
      if(r-l>sz+sz+1){
         f(i,l,l+sz) 
            b[k++]=mp(v[m][i],-1);
         f(i,r-sz,r)
            b[k++]=mp(v[m][i],-1);
      }
      else{
         f(i,l,r)
            b[k++]=mp(v[m][i],-1);
      }
      b[k++]=mp(v[x][i],1);
   }
   mark[t]=0;
   f(i,0,k-1){
      t+=b[i].S;
      if(mark[t]!=-1){
         maxm(ans,b[i+1].F-1-mark[t]);
      }
      else{
         mark[t]=b[i].F;
      }
   }
   t=N;
   f(i,0,k-1){
      t+=b[i].S;
      mark[t]=-1;
   }
}

int main(){
   fill(mark,mark+N+N,-1);
   cin>>n;
   f(i,1,n+1){
      cin>>a[i];
      v[a[i]].pb(i);
      maxm(mx,int(v[a[i]].size()));
   }
   f(i,1,n+1){
      if(mx==v[i].size()){
         if(m) return cout<<n,0;
         m=i;
      }
   }
   f(i,1,n+1)
      if(i!=m)
         solve(i);
   cout<<ans;
}