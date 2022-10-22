#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,m,dp[10099],a[109],mxt[109],x;
int main(){
	scanf("%I64d%I64d",&n,&m);
	f(sal,0,n){
		fill(mxt,mxt+x+1,0);
		scanf("%I64d",&x);
		f(i,1,x+1){
			scanf("%I64d",&a[i]);a[i]+=a[i-1];
		}
		f(i,0,x){
			f(j,i+1,x+1){
				mxt[i+(x-j)]=max(mxt[i+(x-j)],a[i]+a[x]-a[j]);
			}
		}
		mxt[x]=a[x];
		f_(i,m,1){
			f(j,1,min(i,x)+1){
				dp[i]=max(dp[i],dp[i-j]+mxt[j]);	
			}
		}
	}
	cout<<dp[m];
}