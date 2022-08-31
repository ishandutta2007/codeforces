#include <cstdio>
#include <algorithm>

int n,m,f[200001],a[100001],b[100001],top;
long long sum=0;
int find(int x){return f[x]?f[x]=find(f[x]):x;}
struct point{
	int u,v,val;
}num[200001];
bool cmp(point a,point b){
	return a.val>b.val;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	for(int j=1;j<=n;j++)scanf("%d",b+j);
	for(int i=1;i<=m;i++){
		int tem;
		scanf("%d",&tem);
		for(int j=1;j<=tem;j++){
			int tem2;
			scanf("%d",&tem2);
			num[++top]=(point){i+n,tem2,a[i]+b[tem2]};
			sum+=a[i]+b[tem2];
		}
	}
	std::sort(num+1,num+top+1,cmp);
	for(int i=1;i<=top;i++){
		int u=find(num[i].u),v=find(num[i].v);
		if(u!=v){
			f[u]=v;
			sum-=num[i].val;
		}
	}
	printf("%lld\n",sum);
}