#include <cstdio>
#include <algorithm>
using std::max;

int n,a[200001],q,f[200001],fs[200001],c[200001];
bool vis[200001];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void unionn(int x,int y){x=find(x),y=find(y),fs[y]+=fs[x],f[x]=y;}
void update(int ind,int num){for(;ind;ind-=ind&-ind)c[ind]=max(c[ind],num);}
int query(int ind){int tot=0;for(;ind<=n;ind+=ind&-ind)tot=max(tot,c[ind]);return tot;}
struct point{
	int ord,val;
}num[200001];
bool cmp(point a,point b){return a.val>b.val;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),num[i].val=a[i],num[i].ord=i;
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		int tem=num[i].ord;
		vis[tem]=1;
		fs[tem]=1;
		if(vis[tem-1])unionn(tem-1,tem);
		if(vis[tem+1])unionn(tem+1,tem);
		update(fs[find(tem)],num[i].val);
	}
	for(int i=1;i<=n;i++)printf("%d ",query(i));
}