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
 
int ans,n,x,a[N],p[N],g[N];
vector<int> v[N];
 
int main(){
   cin>>n>>x;
   f(i,2,N){
      if(p[i]==0){
         p[i]=1;
         for(int j=i*2;j<N;j+=i)
            p[j]=1;
         for(int j=2;j*i<N && j<=i;j++)
            if(p[j])
               g[i*j]=1;
      }
      else
         p[i]=0;
      g[i]|=p[i];
   }
   g[x]=0;
   f(i,0,N){
      f(j,0,N){
         int mv=0;
         f(k,0,v[j].size())
            if(g[i-v[j][k]]){
               mv=1;
               break;
            }
         if(mv==0){
            a[i]=j;
            v[j].pb(i);
            break;
         }
      }
   }
   f(i,0,n){
      int b,w,r;
      cin>>b>>w>>r;
      ans=ans^a[w-b-1]^a[r-w-1];
   }
   if(ans){
      cout<<"Alice"<<endl<<"Bob";
   }
   else{
      cout<<"Bob"<<endl<<"Alice";
   }
}