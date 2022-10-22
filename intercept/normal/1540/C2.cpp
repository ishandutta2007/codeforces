#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=109;
int n,q;
int c[M],b[M],a[M],dp[M][M*M];
map<int,int>mp;
int work(int x){
	memset(dp,0,sizeof(dp));
	a[1]=x;
	for(int i=2;i<=n;++i)a[i]=a[i-1]+b[i-1];
	int l=0,r=0;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		int L=l-a[i],R=r+c[i]-a[i];
		int u=-a[i],v=c[i]-a[i];
		for(int k=max(0,L);k<=R;++k){
			int s=k-v,t=k-u;
			if(t<0)continue;
			s=max({s,l,0});
			t=min(t,r);
			dp[i][k-L]=(dp[i-1][s-l]+mod-dp[i-1][t+1-l])%mod;
		}
		l=L,r=R;
		for(int j=r-1;j>=l;--j)dp[i][j-l]=(dp[i][j-l]+dp[i][j+1-l])%mod;
	}
	if(r<0)return 0;
	return dp[n][max(-l,0)];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<n;++i)cin>>b[i];
	int ans=work(-1e5);
	int l=-1e5,r=1e5;
	while(l<r){
		int mid=l+r>>1;
		if(work(mid+1)==ans)l=mid+1;
		else r=mid;
	}
	int L=l;
	l=-1e5,r=1e5;
	while(l<r){
		int mid=l+r>>1;
		if(work(mid)==0)r=mid;
		else l=mid+1;
	}
	int R=r;
	cin>>q;
	for(int i=1;i<=q;++i){
		int x;
		cin>>x;
		if(x<=L)cout<<ans<<endl;
		else if(x>=R)cout<<0<<endl;
		else {
			if(!mp.count(x))mp[x]=work(x);
			cout<<mp[x]<<endl;
		}
	}
	return 0;
}
/*
3
2 3 4
2 1
1
-1
*/