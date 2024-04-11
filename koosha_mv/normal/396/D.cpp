#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99,mod=1e9+7,T=500000004;
 
int n,ans,res,a[N],an[N],fac[N],BIT[N];
 
void update(int x,int val) { while(x<=N)  {  BIT[x]+=val;  x+=(x&-x);  } }
int query(int x) { int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 
 
int calc(int x){
    if(x<2) return 0;
    return 1ll*(x-1)*x/2%mod*fac[x]%mod*T%mod;
}
 
int main(){
    fac[0]=1;
    f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod;
    cin>>n;
    f(i,1,n+1) gett(a[i])
    f_(i,n,1){
        update(a[i],1);
        an[i]=query(a[i]);
    }
    f(i,1,N) BIT[i]=0;
    f(i,1,n+1){
        //int m=query(a[i]-1),t=fac[n-i]*m,mv=1ll*t*n*%mod*(n-1)%mod*T%mod;
        int m=an[i]-1,t=1ll*fac[n-i]*m%mod,c1=1ll*calc(n-i)*m%mod,c2=1ll*t*res%mod,c3;
        c3=1ll*max(m-1,0)*t%mod*T%mod;
       // cout<<c1<<" "<<c2<<" "<<c3<<'\n';
        
        update(a[i],1);
        Add(res,a[i]-query(a[i]));
        Add(ans,((c1+c2)%mod+c3)%mod);
    }
    Add(ans,res);
    cout<<ans;
}