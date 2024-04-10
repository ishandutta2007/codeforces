#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

using std::min;

std::set<int>up,dn;
int f[2000001][2],n,m1,m2,t,top,stk1[2000001],top1,stk2[2000001][2],top2;
bool pre[2000001][2],vis[2000001][2];
int obs[2000001];
int main(){
	scanf("%d%d%d%d",&n,&m1,&m2,&t);
	for(int i=1,tem;i<=m1;i++)scanf("%d",&tem),up.insert(tem),obs[++top]=tem,obs[++top]=tem+1;
	for(int i=1,tem;i<=m2;i++)scanf("%d",&tem),dn.insert(tem),obs[++top]=tem,obs[++top]=tem+1;
	std::sort(obs+1,obs+top+1);
	int lim=std::unique(obs+1,obs+top+1)-obs-1;
	memset(f,-1,sizeof f);
	f[0][0]=f[0][1]=0;
	pre[0][1]=1;
	for(int i=1;i<=lim;i++){
		bool bb1=up.count(obs[i]),bb2=dn.count(obs[i]);
		vis[i][0]=bb1,vis[i][1]=bb2;
		if(f[i-1][0]+(obs[i]-obs[i-1])-(bb1?t:0)>0&&f[i-1][0]!=-1)f[i][0]=f[i-1][0]+(obs[i]-obs[i-1])-(bb1?t:0);
		if(f[i-1][1]+(obs[i]-obs[i-1])-(bb2?t:0)>0&&f[i-1][1]!=-1)f[i][1]=f[i-1][1]+(obs[i]-obs[i-1])-(bb2?t:0);
		if((f[i][1]<min(f[i][0],t)||f[i][1]==-1)&&f[i][0]!=-1&&!bb2)f[i][1]=min(f[i][0],t),pre[i][1]=1;
		if((f[i][0]<min(f[i][1],t)||f[i][0]==-1)&&f[i][1]!=-1&&!bb1)f[i][0]=min(f[i][1],t),pre[i][0]=1;
	}
	if(f[lim][0]==-1&&f[lim][1]==-1){
		puts("No");
		return 0;
	}
	puts("Yes");
	int x=lim,y=f[lim][0]==-1?1:0,last=1000000000;
	while((x>0)||(y>0)){
		if(pre[x][y])stk1[++top1]=x,y^=1;
		else --x;
		if(vis[x][y])last=min(last-t,obs[x]-1),++top2,stk2[top2][0]=last,stk2[top2][1]=y;
	}
	printf("%d\n",top1);
	for(int i=top1;i;i--)printf("%d ",obs[stk1[i]]);putchar('\n');
	printf("%d\n",top2);
	for(int i=top2;i;i--)printf("%d %d\n",stk2[i][0],stk2[i][1]+1);
}