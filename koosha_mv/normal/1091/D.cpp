#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,ans[1000009],fac[1000009],mod=998244353;
int main(){
	cin>>n;fac[1]=1;ans[1]=1;
	f(i,2,n+1){
		fac[i]=(fac[i-1]*i)%mod;
		ans[i]=((ans[i-1]+fac[i-1]-1)*i)%mod;
	}
	cout<<ans[n];
}