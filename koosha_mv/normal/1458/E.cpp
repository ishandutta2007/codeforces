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
 
const int N=1e5+22;
 
int n,m,t,p,ans[N],q[N][2],mark[N];
vector<pair<int,int> > v;
vector<pair<pair<int,int>,int> > w;
set<int> s;
 
void do_it(int x,int v,int p){
   v-=x;
   while(1){
      int u=*s.begin();
      if(t+x+1<u){
         while(p<w.size() && w[p].F.F<v+x){
            if(v<=w[p].F.F && w[p].F.F-v==w[p].F.S-t-1){
               ans[w[p].S]=1;
            }
            p++;
         }
         t+=x;
         v+=x;
         return ;
      }
      x-=u-t-1;
      while(p<w.size() && w[p].F.F<v+u-t-1){
         if(v<=w[p].F.F && w[p].F.F-v==w[p].F.S-t-1){
            ans[w[p].S]=1;
         }
         p++;
      }
      v+=u-t-1;
      t=u;
      s.erase(u);
   }
}
 
int main(){
   ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
   s.insert(2e9+1);
   v.pb(mp(0,0));
   v.pb(mp(1e9+1,0));
   cin>>n>>m;
   f(i,0,n){
      int u,x;
      cin>>u>>x;
      v.pb(mp(u,x));
   }
   f(i,0,m){
      cin>>q[i][0]>>q[i][1];
      w.pb(mp(mp(q[i][0],q[i][1]),i));
   }
   n=v.size();
   
   sort(v.begin(),v.end());
   sort(w.begin(),w.end());
   f(i,0,w.size()){
      while(p<v.size() && v[p]<w[i].F) p++;
      if(p<v.size() && v[p]==w[i].F) mark[i]=1;
   }
   p=0;
   int i=0;
   while(i!=n-1){
      int mv=0,j=i,cp=p;
      if(t<v[i].S) mv=1,t++;
      for(;v[j].F==v[i].F;j++){
         s.insert(v[j].S);  
      }
      while(*s.begin()<=t) s.erase(*s.begin());
      while(p<w.size() && w[p].F.F<v[j].F){
         int u=w[p].F.F-v[i].F,x=distance(s.begin(),s.upper_bound(w[p].F.S));
         if((u==0 && t==w[p].F.S && mv) || mark[p] || ans[w[p].S]==1){
            ans[w[p].S]=1;
         }
         else{
            ans[w[p].S]=0;
         }
         p++;
      }
      do_it(v[j].F-v[i].F-1,v[j].F,cp);
      i=j;
   }
   f(i,0,m){
      if(ans[i]) cout<<"LOSE"<<'\n';
      else cout<<"WIN"<<'\n';
   }
}