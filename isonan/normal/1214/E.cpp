#include <cstdio>
#include <algorithm>

int n;
struct point{
	int d,i;
}num[400010];
bool cmp(point a,point b){
	return a.d>b.d;
}
int s[400010],top,fa[400010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i].d),num[i].i=i;
	std::sort(num+1,num+n+1,cmp);
	int top=n,tem=0,l=n-top+1;
	for(int i=1;i<=n;i++)s[i]=num[i].i*2-1;
	for(int i=1;i<top;i++)printf("%d %d\n",s[i],s[i+1]);
	for(int i=1;i<=n;++i){
		int len=num[i].d+i-1;
		{
			if(len==top){
				s[++top]=num[i].i*2;
				printf("%d %d\n",s[top],s[top-1]);
			}
			else printf("%d %d\n",s[len],num[i].i*2);
		}
	}
}