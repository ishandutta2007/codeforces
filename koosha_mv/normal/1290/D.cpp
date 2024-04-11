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
 
const int N=1111;

int n,k,ans,g[N][N],mark[N];
vector<int> v[N];

void dfs(int x){
   f(i,0,v[x].size()){
      char c;
      cout<<"? "<<v[x][i]+1<<endl;
      cin>>c;
      if(c=='Y' && !mark[v[x][i]]){
         ans--;
         mark[v[x][i]]++;
      }
   }
   f(i,x+1,n)
      if(g[x][i]){
      	dfs(i);
         g[x][i]=0;
         return ;
      }
   cout<<'R'<<endl;
}

int main(){
   cin>>n>>k;
   if(k==1) k=2;
   k/=2,ans=n;
   f(i,0,n)
      v[i/k].pb(i);
   n=n/k;
   f(i,0,n)
      f(j,i+1,n)
         g[i][j]=1;
   f(i,0,n){
      f(j,i+1,n)
         if(g[i][j])
            dfs(i);
   }
   cout<<"! "<<ans<<endl;
}