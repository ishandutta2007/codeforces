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

const int N=4e5+99,mod=998244353;

int n,m,t,a[N],p[N],fac[N],BIT[N];

void update(int x,int val) { while(x<N)  {  BIT[x]+=val;  x+=(x&-x);  } }
int query(int x) {  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 

int pow(int x,int y,int mod){
   if(y==0) return 1;
   int res=pow(1ll*x*x%mod,y/2,mod);
   if(y&1) res=1ll*res*x%mod;
   return res;
}

int main(){
   fac[0]=1;
   f(i,1,N){
      fac[i]=1ll*fac[i-1]*i%mod;
      update(i,1);
   }
   cin>>t;
   while(t--){
      vector<int> v;
      cin>>n>>m;
      int x=n;
      f(i,0,m){
      	int x;
         Gett(x,a[i]);
      }
      f_(i,m-1,0){
         int l=0,r=n+1;
         while(l+1<r){
            int mid=(l+r)/2;
            if(query(mid)<a[i]) l=mid;
            else r=mid;
         }
         if(query(r)<query(r+1)) x--;
         update(r,-1);
         v.pb(r);
      }
      f(i,0,v.size())
      	update(v[i],1);
      if(m<n) x--;
      int ans=1ll*pow(fac[n],mod-2,mod)*pow(fac[x],mod-2,mod)%mod*fac[n+x]%mod;
      cout<<ans<<'\n';
   }
}