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
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5005,Mx=1e9;

int n,t,ans=N,a[N],dp[N];

int main(){
	cin>>n;
	f(i,1,n+1) gett(a[i]);
	dp[0]=0;
	ans=n;
	f(i,1,n+1){
		int mn=Mx;
		dp[i]=Mx;
		f_(j,i-1,0){
		    minm(mn,a[j]);
		    minm(dp[i],dp[j]+max(0,a[i]-mn)+i-j-1);
		}
		minm(ans,dp[i]+n-i);
	}
	cout<<ans;
}