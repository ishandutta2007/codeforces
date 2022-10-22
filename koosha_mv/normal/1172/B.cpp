#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll x,y,ans=1,n,mod=998244353,deg[200009],fac[200009];
int main(){
	fac[0]=1;cin>>n;
	f(i,1,200009) fac[i]=(fac[i-1]*i)%mod;
    f(i,0,n-1){
    	scanf("%I64d%I64d",&x,&y);
    	deg[x-1]++;deg[y-1]++;}
    f(i,0,n) ans=(ans*fac[deg[i]])%mod;
    cout<<(ans*n)%mod;
}