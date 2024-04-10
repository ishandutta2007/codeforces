#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int a[M],vis[M*20],in[M],dp[21];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=20;++i){
		for(int j=1;j<=m;++j){
			dp[i]+=!vis[i*j];
			vis[i*j]=1;
		}		
	}
	for(int i=2;i<M;++i){
		if(in[i])continue;
		for(int j=i;j<M;j+=i){
			in[j]=1;
			int x=j,t=0;
			while(x%i==0)x/=i,t++;
			a[j]=__gcd(a[j],t);
		}
	}
	ll ans=1;
	for(int i=2;i<=n;++i)ans+=dp[a[i]];
	cout<<ans;
	return 0;
}