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
 
const int N=2e5+99;

int n,m,res[N],c[N];
ll ans;
pair<int,int> a[N],b[N];

ll calc(int x){
   vector<pair<pair<int,int> ,int> > v;
   ll ans=0;
   vector<int> d[2];
   f(i,0,x){
      ans+=a[i].F+m-b[n-i-1].F;
      res[a[i].S]=b[n-i-1].S;
   }
   int p1=x,p2=0;
   while(p1<n || p2<n-x){
      if(p2==n-x || (p1<n && a[p1].F<b[p2].F))
         v.pb(mp(a[p1++],0));
      else
         v.pb(mp(b[p2++],1));
   }
   f(i,0,v.size()){
      if(d[1-v[i].S].size()){
         if(v[i].S==0){
            res[v[i].F.S]=d[1].back();
         }
         else{
            res[d[0].back()]=v[i].F.S;
         }
         d[1-v[i].S].pop_back();
         ans+=v[i].F.F;
      }
      else{
         ans-=v[i].F.F;
         d[v[i].S].pb(v[i].F.S);
      }
   }
   return ans;
}
void solve(int o){
   int l=0,r=n+1;
   while(l+1<r){
      int mid=(l+r+1)/2;
      if(calc(mid-1)<calc(mid)) r=mid;
      else l=mid;
   }
   if(calc(l)<ans){
      ans=calc(l);
      f(i,0,n){
         if(o==0) c[i]=res[i];
         else c[res[i]]=i;
      }
   }
}

int main(){
   ans=1e18;
   cin>>m>>n;
   f(i,0,n){
      gett(a[i].F);
      a[i].S=i;
   }
   f(i,0,n){
      gett(b[i]);
      b[i].S=i;
   }
   sort(a,a+n);
   sort(b,b+n);
   solve(0);
   f(i,0,n) swap(a[i],b[i]);
   solve(1);
   cout<<ans<<endl;
   f(i,0,n) cout<<c[i]+1<<" ";
}