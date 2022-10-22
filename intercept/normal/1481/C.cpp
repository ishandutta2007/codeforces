#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int M=1e5+9;
int n,k;
int a[M],b[M],c[M],l[M],ans[M];
vector<int>d[M];
int vis[M];
void work(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		d[i].clear();
		l[i]=0;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		vis[b[i]]=i;
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		d[c[i]].pb(i);
		l[c[i]]++;
		ans[i]=0;
	}
	int mi=0,po=0;
	for(int i=1;i<=n;++i){
		if(a[i]!=b[i]){
			if(l[b[i]]==0){
				printf("NO\n");
				return;
			}
			ans[d[b[i]][--l[b[i]]]]=i;
			if(mi<d[b[i]][l[b[i]]]){
				mi=d[b[i]][l[b[i]]];
				po=i;
			}
		}
	}
	for(int i=1;i<=k;++i){
		if(!ans[i]&&vis[c[i]]){
			if(mi<i){
				mi=i;
				po=vis[c[i]];
			}
		}
	}
	for(int i=mi+1;i<=k;++i){
		if(!ans[i]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for(int i=1;i<=k;++i){
		if(!ans[i])printf("%d ",po);
		else printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
3 10000000
5 3 1

*/