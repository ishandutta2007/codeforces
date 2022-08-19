#include <cstdio>
#include <cstdlib>
#include <algorithm>

struct point{
	int val,ord;
}num[200001];
bool cmp(point a,point b){return a.val<b.val;}
int n,m,d,ch[200001][2],val[200001],belong[200001],pri[200001],nxt[200001],tem[200001],root,cnt;
bool vis[200001];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i].val);
		num[i].ord=i;
	}
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++)tem[i]=num[i].val;
	for(int i=1;i<=n;i++){
		if(tem[n]<=tem[i]+d)nxt[i]=n+1;
		else nxt[i]=std::upper_bound(tem+1,tem+n+1,tem[i]+d)-tem;
	}
	int x=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int tem=i;
			x++;
			while(tem<=n){
				while(vis[tem])tem++;
				if(tem>n)break;
				belong[num[tem].ord]=x;
				vis[tem]=1;
				tem=nxt[tem];
			}
		}
	}
	printf("%d\n",x);
	for(int i=1;i<=n;i++)printf("%d ",belong[i]);
}