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

const int N=1e5+99,sq=500;

int n,a[N],s[N],prime[N],mark[N],cnt[sq][N];
vector<int> d[N],v[N];
ll res;

void read(){
   cin>>n;
   f(i,0,n){
      int x;
      cin>>x;
      a[x]=1;
   }
   f(i,1,N){
      for(int j=i;j<N;j+=i)
         a[i]|=a[j];
   }
}
void do_it(){
   f(i,2,N){
      if(!prime[i]){
         for(int j=i;j<N;j+=i)
            prime[j]++;
      }
   }
   f(i,2,N){
      if(!mark[i]){
         for(int j=i*min(i,sq);j<N;j+=i*i)
            mark[j]=1;
         for(int j=i;j<N;j+=i){
            d[j].pb(i);
            if(i>=sq && a[j]){
               v[i].pb(j);
            }
            if(i<sq && a[j]){
               cnt[i][j]=1;
            }
         }
      }
   }
   f(i,1,sq){
      if(!mark[i]){
         f_(j,N-2,0){
            cnt[i][j]+=cnt[i][j+1];
            if(i==1 && a[j]) cnt[i][j]++;
         }
      }
   }
}
int calc(int u,int k){
   int l=-1,r=v[u].size(),mid;
   while(l+1<r){
      mid=(l+r)/2;
      if(v[u][mid]<k) 
         l=mid;
      else
         r=mid;
   }
   return v[u].size()-r;
}
int check(int x,int k){
   int ans=0;

   f(i,0,d[x].size()){
      int res=0,u=d[x][i];
      if(u<sq)
         res=cnt[u][k];
      else
         res=calc(u,k);
      if(prime[u]&1)
         ans+=res;
      else
         ans-=res;
   }
   return ans;
}
void solve(){
   f(i,1,N){
      if(a[i]){
         int l=1,r=N,mid;
         while(l+1<r){
            mid=(l+r)/2;
            if(check(i,mid)<cnt[1][mid])
               l=mid;
            else
               r=mid;
         }
         maxm(res,1ll*i*l);
      }
   }
   cout<<res<<endl;
}

int main(){
   read();
   do_it();
   solve();
}