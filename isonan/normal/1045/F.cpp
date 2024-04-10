#include <algorithm>
#include <cstdlib>
#include <cstdio>

int n;
struct point{
	long long x,y;
}num[400010],tem[400010],bb[400010];
point operator-(point a,point b){return (point){a.x-b.x,a.y-b.y};}
long long operator*(point a,point b){return a.x*b.y-a.y*b.x;}
bool cmp2(point a,point b){return (a*b)<0||((a*b)==0&&(a.x<b.x||(a.x==b.x&&a.y<b.y)));}
int stk[400020],top,ttop,tstk[400020];
void gethull(int n,point *num,bool add){
	std::sort(num+1,num+n+1,cmp2);
//	puts("");
//	for(int i=1;i<=n;i++)printf("%d %d\n",num[i].x,num[i].y);
	top=0;
	stk[++top]=0;
	num[0]=(point){0,0};
	for(int i=1;i<=n;i++){
		while(top>1&&(num[i]-num[stk[top-1]])*(num[stk[top]]-num[stk[top-1]])<=0){
//			printf("-%d %d\n",num[stk[top]].x,num[stk[top]].y);
			if(add)tem[++ttop]=num[stk[top]];
			--top;
		} 
		stk[++top]=i;
	}
//	puts("");
//	for(int i=1;i<=top;i++)printf("%d %d\n",num[stk[i]].x,num[stk[i]].y);
	for(int i=1;i<=top;i++){
		if(num[stk[i]].x%2==1||num[stk[i]].y%2==1){
			puts("Ani");
			exit(0);
		}
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&num[i].x,&num[i].y);
	}
	gethull(n,num,1);
//	putchar('*');
//	for(int i=1;i<=ttop;i++)printf("%d %d\n",tem[i].x,tem[i].y);
	memcpy(tstk,stk,sizeof stk);
	int now=ttop,siz=top;
	memcpy(bb,tem,sizeof tem);
	for(int i=1;i<=siz;i+=2)if(num[tstk[i]].x||num[tstk[i]].y)bb[++now]=num[tstk[i]];
	gethull(now,bb,0);
	for(int i=2;i<=siz;i+=2)if(num[tstk[i]].x||num[tstk[i]].y)tem[++ttop]=num[tstk[i]];
	gethull(ttop,tem,0);
	puts("Borna");
}