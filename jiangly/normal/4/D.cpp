//Time Complexity : O(N*log(N))
//Space Complexity : O(N*log(N))
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
bool cmp(tuple<int,int,int>a,tuple<int,int,int>b){
	return get<1>(a)!=get<1>(b)?get<1>(a)<get<1>(b):get<2>(a)>get<2>(b);
}
int main(){
	int n,w,h;
	tuple<int,int,int>a[N+1];
	int tot=0;
	int f[N+1]={},dp[N+1]={};
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;++i){
		get<0>(a[i])=i;
		scanf("%d%d",&get<1>(a[i]),&get<2>(a[i]));
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(get<1>(a[i])<=w||get<2>(a[i])<=h){
			continue;
		}
		if(get<2>(a[i])>f[tot]){
			dp[i]=++tot;
			f[tot]=get<2>(a[i]);
		}else{
			dp[i]=lower_bound(f,f+tot+1,get<2>(a[i]))-f;
			f[dp[i]]=get<2>(a[i]);
		}
	}
	int top=0;
	int st[N+1]={};
	printf("%d\n",tot);
	for(int i=n,j=tot;i&&j;--i){
		if(dp[i]==j){
			st[++top]=get<0>(a[i]);
			--j;
		}
	}
	while(top){
		printf("%d ",st[top--]);
	}
	return 0;
}