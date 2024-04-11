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
 
const int N=1e3+99;

int n,t,c,a[N],mark[N];
char ans[N][N];

int main(){
   f(i,0,N) f(j,0,N) ans[i][j]='.';
   cin>>n; c=n;
   f(i,1,n+1) cin>>a[i];
   f(i,1,n+1){
      if(!mark[i] && a[i]!=i){
         vector<int> v;
         for(int u=i;!mark[u];u=a[u]){
            v.pb(u);
            mark[u]=1;
         }
         if(t!=0){
            ans[c][v[0]]=ans[c][t]='-';
            vector<int> nv;
            nv.pb(t);
            f(i,1,v.size())
               nv.pb(v[i]);
            nv.pb(v[0]);
            v=nv;
         }
         else t=i;
         f_(j,v.size()-2,0){
            if(v[j]<v[j+1]){
               ans[c][v[j]]=ans[c][v[j+1]]='/';
            } 
            else{
               ans[c][v[j]]=ans[c][v[j+1]]='-';
            }
            c--;
         }
         
      }
   }
   cout<<n-(t>0)<<endl;
   f(i,1,n+1){
      f(j,1,n+1){
         if(ans[i][j]=='-') cout<<"\\";
         else cout<<ans[i][j];
      }
      cout<<endl;
   }
}