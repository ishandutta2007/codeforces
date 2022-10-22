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
 
const int N=3e6+9;

int n,m,a[N],cnt[N];
ll ans[N];

int main(){
   cin>>n;
   f(i,0,n){
      int x;
      gett(x);
      cnt[x]++;
   }
   f(i,1,N){
      for(int j=1;j*i<N;j++){
         if(i==j) ans[i*j]+=cnt[i]*(cnt[i]-1);
         else ans[i*j]+=cnt[i]*cnt[j];
      }
   }
   f(i,1,N)
      ans[i]+=ans[i-1];
   cin>>m;
   f(i,0,m){
      int x;
      gett(x);
      cout<<1ll*n*(n-1)-ans[x-1]<<" ";
   }
}