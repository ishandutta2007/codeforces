#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,ans;
ll a[M],sum[M],pc[M];
void add(int &x,int y){x+=y;x>=mod?x-=mod:0;}
void solve(int id,int li,ll x){
	for(int i=id;i<n-li;++i){
		int l=0,r=(n-i-1-li)/2;
		while(l<=r){
			int mid=l+r>>1;
			if((sum[i]+pc[i+mid*2]-pc[i]+x)*2<sum[n])l=mid+1;
			else r=mid-1;
		}
		add(ans,l);
	}
}
void work(){
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		pc[i]=pc[max(i-2,0)]+a[i];
	}
	for(int i=1;i<=n;++i){
		if(sum[i]*2>sum[n])add(ans,1);
	}
	
	solve(1,0,0);
	solve(1,1,a[n]);
	sum[1]=pc[1]=0;
	for(int i=2;i<n;++i){
		sum[i]=sum[i-1]+a[i];
		pc[i]=pc[i-2]+a[i];
	}
	solve(2,0,0);
	solve(2,1,a[n]);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}