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
 
const int N=1e6+99;

int n,sz,now,ind,sum=0,m,a[N],b[N],cp[N];
vector<int> V;

int main(){
   ios_base::sync_with_stdio(0), cin.tie(0);
   cin>>m>>n;
   f(i,0,n){
      cin>>a[i];
      cp[i]=a[i];
      sum+=a[i];
   }
   V.pb(m);
   sum=(sum+m-1)/m;
   int ans[sum][n];
   f(i,0,sum){
      vector<int> VN;
      f(j,0,V.size()){
         //cout<<j<<" "<<now<<" "<<a[now]<<endl;
         if(V[j]<=a[now] || now==n-1){ a[now]-=V[j],VN.pb(V[j]); }
         else{
            b[j]=a[now];
            V[j]-=b[j];
            a[now]=0;
            VN.pb(b[j]);
            j--;
         }
         now+=(a[now]<=0);
         if(now==n){
            f(k,j+1,V.size()) VN.pb(V[k]);
            break;
         }
      }
      V=VN;
      //cout<<"V : "; f(j,0,V.size()) cout<<V[j]<<" "; cout<<endl;
   }
   f(i,0,n) a[i]=cp[i];
   f(i,0,V.size()) b[i]=V[i];
   now=n-1;
   f_(i,sum-1,0){
      f_(j,n-1,0){
         ans[i][j]=now;
         a[now]-=b[j];
         if(a[now]<=0 && now>0) now--;
      }
   }
   cout<<sum<<endl;
   f(i,0,n) cout<<b[i]<<" ";
   cout<<endl;
   f(i,0,sum){
      f(j,0,n)
         cout<<max(ans[i][j],ans[i][j])+1<<" ";
      cout<<'\n';
   }
}