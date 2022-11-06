#include<stdio.h>
#include<algorithm>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
struct node{int l,r;}a[200005];
inline bool cmp(node x,node y){return x.r!=y.r?x.r<y.r:x.l<y.l;}
int main(){
	int n;scanf("%d",&n);
	REP(i,1,n){
		int x,y;scanf("%d%d",&x,&y);
		a[i].l=x-y,a[i].r=x+y;
	}
	std::sort(a+1,a+1+n,cmp);
	int R=-2e9,ans=0;
	REP(i,1,n)if(a[i].l>=R)R=a[i].r,++ans;
	printf("%d\n",ans);
	return 0;
}