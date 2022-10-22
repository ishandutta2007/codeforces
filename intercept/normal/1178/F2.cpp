#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=1000009;
const int mod=998244353;
int n,m,num;
int L[M],R[M];
int a[M],c[M<<1],dp[1009][1009],f[M][23];
int ask(int l,int r){
	if(l>r)return n+1;
	int k=log2(r-l+1);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)L[i]=m+1;
	for(int i=1;i<=m;++i){
		scanf("%d",&a[i]);
		L[a[i]]=min(L[a[i]],i);
		R[a[i]]=max(R[a[i]],i);
		f[i][0]=a[i];
	}
	for(int j=1;j<=20;++j){
		for(int i=1;i+(1<<j)-1<=m;++i){
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=n;++i){
		if(L[i]<=m)c[num++]=L[i];
		if(R[i]>L[i])c[num++]=R[i];
	}
	sort(c,c+num);
	for(int i=1;i<=n;++i){
		L[i]=lower_bound(c,c+num,L[i])-c;
		R[i]=lower_bound(c,c+num,R[i])-c;
	}
	for(int i=0;i<=num;++i){
		for(int j=0;j<=num;++j)dp[i][j]=1;
	}
	for(int k=1;k<=num;++k){
		for(int l=0;l<num;++l){
			int r=l+k;
			bool flag=0;
			int mi=n;
			for(int i=l;i<r;++i){
				if(L[a[c[i]]]<l||R[a[c[i]]]>=r){
					flag=1;
					break;
				}
				mi=min(mi,a[c[i]]);
			}
			if(flag){
				dp[l][r]=0;
				continue;
			}
			int pl=L[mi],pr=R[mi],vl=0,vr=0;
			if(ask(c[pl],c[pr])<mi){
				dp[l][r]=0;
				continue;
			}
			for(int i=l;i<=pl;++i){
				if(ask(c[i],c[pr])>=mi)vl=(vl+1ll*dp[l][i]*dp[i][pl]%mod)%mod;
			}
			for(int i=pr+1;i<=r;++i){
				if(ask(c[pl],c[i-1])>=mi)vr=(vr+1ll*dp[pr+1][i]*dp[i][r]%mod)%mod;
			}
			
			dp[l][r]=1ll*vl*vr%mod*dp[pl+1][pr]%mod;
		}
	}
	printf("%d\n",dp[0][num]);
	return 0;
}
/*
8 10
1 3 2 7 8 2 5 4 6 1
*/