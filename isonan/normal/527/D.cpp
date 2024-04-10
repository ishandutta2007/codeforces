#include <cstdio>
#include <algorithm>

int q[200001],h,t,n;
struct point{
	int l,r;
}num[200001];
bool cmp(point a,point b){return (a.r<b.r)||(a.r==b.r&&a.l<b.l);}
int main(){
	scanf("%d",&n);
	for(int i=1,x,w;i<=n;i++){
		scanf("%d%d",&x,&w);
		num[i].l=x-w;
		num[i].r=x+w;
	}
	std::sort(num+1,num+n+1,cmp);
	int ans=0,now=num[1].l-1;
	for(int i=1;i<=n;i++)
		if(now<=num[i].l)now=num[i].r,ans++;
	printf("%d\n",ans);
}