#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
int a[109][109],b[109][109];
pii id[10009];
bool vis[109][109];
bool cmp(pii l,pii r){
	return a[l.fi][l.se]<a[r.fi][r.se];
}
void work(){
	scanf("%d%d",&n,&m);
	int num=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			b[i][j]=0;
			scanf("%d",&a[i][j]);
			id[++num]=pii{i,j};
		}
	}
	sort(id+1,id+num+1,cmp);
	for(int i=1,j=1;i<=num;++i,j=j%m+1){
		while(b[id[i].fi][j])j=j%m+1; 
		b[id[i].fi][j]=a[id[i].fi][id[i].se];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}