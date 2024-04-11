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
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6,W=13;

int n,m,w,mask,ma3k,a[N],cnt[N],Pow[W];
vector<int> e[6],v[W];
string s="AOXaox";

void make(){
   e[3].pb(2);
   e[0].pb(0);
   e[0].pb(1);
   e[4].pb(1);
   e[4].pb(2);
   e[1].pb(0);
   e[5].pb(1);
   e[2].pb(0);
   e[2].pb(2);
}
int calc(int x,int y){
   int res=0;
   f(i,0,w){
      int u=x%2+y%2;
      x/=2,y/=2;
      res+=u*Pow[i];
   }
   return res;
}
void add(int x){
   if(mask&(1<<x)){
      ma3k-=Pow[x]*v[x][1];
      ma3k+=Pow[x]*v[x][0];
      mask-=(1<<x);
      add(x+1);
   }
   else{
      if(v[x].size()==1){
         add(x+1);
      }
      else{
      	if(v[x].size()){
        		ma3k-=Pow[x]*v[x][0];
        		ma3k+=Pow[x]*v[x][1];
      	}
         mask+=(1<<x);
      }
   }
}

int main(){
   make();
   Pow[0]=1;
   f(i,1,W)
      Pow[i]=3*Pow[i-1];
   cin>>w>>n>>m;
   f(i,0,n){
      int x;
      cin>>x;
      a[x]++;
   }   
   f(i,0,(1<<w))
      f(j,0,(1<<w)){
         cnt[calc(i,j)]+=a[i]*a[j];
      }
   f(q,0,m){
      string t;
      cin>>t;
      reverse(t.begin(),t.end());
      f(i,0,w){
         f(j,0,6)
            if(t[i]==s[j])
               v[i]=e[j];
         //f(j,0,v[i].size()) cout<<v[i][j]<<" "; cout<<endl;
      }
      int ans=0;
      ma3k=mask=0;
      f(i,0,w)
         ma3k+=Pow[i]*v[i][0];
      while(mask<(1<<w)){
         ans+=cnt[ma3k];
         add(0);
      }
      cout<<ans<<endl;
      f(i,0,w) v[i].clear();
   }
}