#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=505;
 
int n,t,p,ans=N*2,a[N],b[N],check[N],mn,mx;
ll sa,sb,k;
bool dp[N*2];
 
int main(){
	dp[0]=1,check[0]=1;
	cin>>n>>k;
	f(i,0,n){
		mn=1e9;
		mx=0;
		cin>>a[i]>>b[i];
		sa+=1ll*a[i],sb+=1ll*b[i];
		mn=max(1ll,k-b[i]);
		mx=min(1ll*a[i],k);
		f_(j,k*2-1,0){
			f(l,mn,min(mx,j)+1)
				dp[j]=(dp[j] || dp[j-l]);
			if(dp[j])
				check[j%k]=1;
		}
		f(j,0,k)
			dp[j]=(dp[j] || dp[j+k]);
	}
	f(i,0,k)
		if(check[i]){
			p=(k-i)%k;
			minm(ans,int(((sa-i)%k)+((sb-p)%k)));
		}
	cout<<(sb+sa-ans)/k;
}