#include <cstdio>
#include <vector>
#include <algorithm>

int n,a[1000001],t;
struct point{
	long long s;
	int ord;
}num[1000001];
bool bad[1000001];
bool vis[1000001];
int p[1000001],stk[2000001],top;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i),p[i]=i-a[i],vis[i]=0;
		top=0;
		int tem=1;
		for(;;){
			if(vis[tem])break;
			vis[tem]=1;
			stk[++top]=tem;
			tem=p[tem];
		}
		int cnt=0;
		for(int i=top;i;i--){
			if(stk[i]==tem){
				cnt=i-1;
				break;
			}
		} 
		printf("%d\n",top-cnt);
		for(int i=cnt+1;i<=top;i++)printf("%d ",stk[i]);putchar('\n');
	}
}