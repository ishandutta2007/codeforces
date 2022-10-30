#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
 
int j,k,n,t,i;
ll a[500500],res,r=1;
 
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		r=r*ksm(i,M-2)%M;
		r=r*(n+i)%M;
	}
	for(i=1;i<=n+n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+n+1);
	for(i=1;i<=n;i++){
		res+=(a[i+n]-a[i]);res%=M;
	}
	printf("%lld\n",res*r%M);
}