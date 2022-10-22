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
 
const int N=15,mod=1e9+7;
 
int n,ans,a[N],dp[(1<<N)],pd[(1<<N)],mv[(1<<N)],sum[(1<<N)],Pow[(1<<N)][N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
 
int Cnt(int mask){
	return __builtin_popcount(mask);
}
void solve(int mask){
    int m=0,res=0,t=0;
    mv[mask]=1;
    f(i,0,n){
        if(mask&(1<<i)){
            t++;
            f(j,0,i){
                if(mask&(1<<j)){          	
                    mv[mask]=1ll*mv[mask]*(a[i]+a[j])%mod;
                }
            }
        }
    }
    int inv=(1<<n)-mask-1;
    m=((inv+1)&mask);
    while(m){
        Add(pd[mask],1ll*dp[m]*(pd[mask-m]+dp[mask-m])%mod*Pow[m][Cnt(mask-m)]%mod);
        m=(((m|inv)+1)&mask);
    }
    dp[mask]=(mv[mask]+mod-pd[mask])%mod;
}
 
int main(){
	mv[0]=1;
    cin>>n;
    f(i,0,n) cin>>a[i];
    f(mask,0,(1<<n)){
    	Pow[mask][0]=Pow[mask][1]=1;
        f(j,0,n)
            if(mask&(1<<j))
                Pow[mask][1]=1ll*Pow[mask][1]*a[j]%mod;
        f(i,2,N) Pow[mask][i]=1ll*Pow[mask][i-1]*Pow[mask][1]%mod;
    }
    f(i,1,(1<<n)){
        solve(i);
    }
    f(mask,1,(1<<n)){
    	Add(ans,1ll*Cnt(mask)*dp[mask]%mod*Pow[mask][n-Cnt(mask)]%mod*mv[(1<<n)-mask-1]%mod);
	}
	cout<<1ll*ans*pow(mv[(1<<n)-1],mod-2,mod)%mod;
}