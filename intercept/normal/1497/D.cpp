#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const ll INF=-1ll<<60;
const int M=5009;
int n;
int tag[M],s[M];
ll pre[M],suf[M];
void work(){
	scanf("%d",&n);ll ans=0;
	for(int i=1;i<=n;++i)scanf("%d",&tag[i]),suf[i]=pre[i]=0;
	for(int i=1;i<=n;++i){
		suf[i]=pre[i]=0;
		scanf("%d",&s[i]);
		for(int j=i-1;j>=1;--j){
			suf[j]=suf[j+1];
			if(tag[i]!=tag[j])suf[j]=max(suf[j],pre[j]+abs(s[j]-s[i]));
			if(tag[i]!=tag[j])pre[j]=max(pre[j],suf[j+1]+abs(s[j]-s[i]));
			ans=max({ans,pre[j],suf[j]});
		}
		pre[i]=suf[1];
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
4
1 2 3 4
5 10 15 20
dpjk->dp ij k<i 
dpjk->dp ij i<k<=j
*/