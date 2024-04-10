#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL P=998244353;
const int N=2e5+100;
const double PI=acos(-1);
const int E=320;
int n,K;
int a[N],b[N],pos[N];
bool vis[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K);
		vis[0]=vis[n+1]=0;
		for(int i=1;i<=n;++i) {
			scanf("%d",&a[i]);
			pos[a[i]]=i;
			vis[i]=1;
		}
		for(int i=1;i<=K;++i) scanf("%d",&b[i]);
		LL ans=1,res;int x;
		for(int i=K;i>=1;--i){
			res=0;x=pos[b[i]];
			if(vis[x-1]) ++res;
			if(vis[x+1]) ++res;
			ans=ans*res%P;
			vis[x]=0;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
/*
4 4
3 0 1 2
2 1 0 2
3 2 1 1
1 1 0 2
*/