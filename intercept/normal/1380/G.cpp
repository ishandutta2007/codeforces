#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=3e5+9;
int n;
int a[M];
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)a[i]=(a[i]+a[i-1])%mod;
	for(int k=1;k<=n;++k){
		int r=n-k,t=1,ans=0;
		while(r){
			ans=(ans+1ll*(a[r]+mod-a[max(r-k,0)])*t%mod)%mod;
			r-=min(r,k);
			t++;
		}
		cout<<1ll*ans*kpow(n,mod-2)%mod<<" \n"[k==n];
	}
	return 0;
}