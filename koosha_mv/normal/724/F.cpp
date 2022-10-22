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

const int N=1002,D=12;

int n,d,mod,inv,C[D],dp[D][N],res[D][N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int main(){
	cin>>n>>d>>mod;
	dp[0][1]=1;
	inv=mod/2+1;
	if(n<3) return cout<<1,0;
	f(i,1,(n+1)/2){
		int num=max(dp[d-1][i],int(i==1));
		C[0]=1; f(i,1,D) C[i]=1ll*C[i-1]*pow(i,mod-2,mod)%mod*(num+i-1)%mod;
		f_(j,n-i,1)
			for(int k=1;k*i+j<=n;k++)
				f(o,0,d+1)
					if(o+k<D) 
					Add(dp[o+k][j+k*i],1ll*dp[o][j]*C[k]%mod);
	}
	cout<<(dp[d][n]+((n+1)&1)*(1ll*dp[d-1][n/2]*(dp[d-1][n/2]+1)%mod*inv%mod))%mod;
}