#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,mod,fac[250009],ans;
int main(){
	cin>>n>>mod;fac[0]=1;n++;
	f(i,1,250006){
		fac[i]=(fac[i-1]*i)%mod;
	}
	f(i,1,n){
		ans+=((((((n-i)*(n-i))%mod)*fac[i])%mod)*fac[n-i-1])%mod;ans%=mod;
	}
	cout<<ans;
}