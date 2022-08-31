#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#define int long long

struct point{
	long long x,y;
}num[1025],v[11];
struct info{
	point p;
	int val,l,r,ord;
	long long cmp;
}f[100010],p[100010],que[200010];
long long ans[100010];
point operator+(point a,point b){return (point){a.x+b.x,a.y+b.y};}
point operator-(point a,point b){return (point){a.x-b.x,a.y-b.y};}
point operator*(point a,int n){return (point){1ll*n*a.x,1ll*n*a.y};}
bool cmp1(point a,point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
long long operator*(point a,point b){return 1ll*a.x*b.y-1ll*a.y*b.x;}
bool cmp2(point a,point b){return (a*b)<0ll||((a*b)==0ll&&(a.x<b.x||(a.x==b.x&&a.y<b.y)));}
int stk[3001],top,cnt,A,B,orig[100010],lim,ind[100010];
long long c[100010];
void update(int ind,int num){for(;ind<=lim;ind+=ind&-ind)c[ind]+=num;}
long long query(long long x){
	int ind=std::upper_bound(orig+1,orig+lim+1,x)-orig-1;
//	printf("query %lld %d\n",x,ind);
	long long tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
int k,n,q;
bool cmp(info a,info b){return (a.cmp<b.cmp)||(a.cmp==b.cmp&&a.val<b.val);}
signed main(){
	scanf("%lld%lld%lld",&k,&n,&q);
	for(int i=1;i<=k;i++)scanf("%lld%lld",&v[i].x,&v[i].y);
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1)))num[i]=num[i]+v[j];
			else num[i]=num[i]-v[j];
//		printf("%d %d\n",num[i].x,num[i].y);
	}
	std::sort(num,num+(1<<k),cmp1);
	for(int i=1;i<(1<<k);i++)num[i]=num[i]-num[0];
	std::sort(num+1,num+(1<<k),cmp2);
	for(int i=1;i<(1<<k);i++)num[i]=num[i]+num[0];
	for(int i=0;i<(1<<k);i++){
		while(top>1&&(num[i]-num[stk[top-1]])*(num[i]-num[stk[top]])>=0ll)--top;
		stk[++top]=i;
	}
	stk[top+1]=0;
//	putchar('\n');
//	for(int i=1;i<=top;i++)printf("%d %d\n",num[stk[i]].x,num[stk[i]].y);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&f[i].p.x,&f[i].p.y,&f[i].val),orig[i]=f[i].p.x;
	std::sort(orig+1,orig+n+1);
	lim=std::unique(orig+1,orig+n+1)-orig-1;
//	for(int i=1;i<=lim;i++)printf("*%d ",orig[i]);putchar('\n');
	for(int i=1;i<=n;i++)ind[i]=std::lower_bound(orig+1,orig+lim+1,f[i].p.x)-orig;
	for(int i=1;i<=q;i++)scanf("%lld%lld%lld",&p[i].p.x,&p[i].p.y,&p[i].val);
	for(int i=1;i<=top;i++){
		cnt=0;
		memset(c,0,sizeof c);
		B=num[stk[i]].x-num[stk[i+1]].x,A=num[stk[i]].y-num[stk[i+1]].y;
		if(B<0)B=-B,A=-A;
		for(int j=1;j<=q;j++)
			que[++cnt]=(info){
				p[j].p+num[stk[i]]*p[j].val,
				(num[stk[i]].x<num[stk[i+1]].x?1e18:-1e18),
				p[j].p.x+1ll*num[stk[i]].x*p[j].val,
				p[j].p.x+1ll*num[stk[i+1]].x*p[j].val,
				j,0};
		for(int j=1;j<=n;j++)
			que[++cnt]=(info){
				f[j].p,
				f[j].val,
				ind[j],
				0x7f7f7f7f,
				-1,0};
		if(!B){
			for(int j=1;j<=cnt;j++)
				que[j].cmp=que[j].p.x*1000000000ll+que[j].p.y;
		}
		else{
			for(int j=1;j<=cnt;j++){
				que[j].cmp=B*que[j].p.y-A*que[j].p.x;
			}
		}
		std::sort(que+1,que+cnt+1,cmp);
//		puts("new");
		for(int j=1;j<=cnt;j++){
//			if(!~que[j].ord)printf("Add %lld %lld %lld\n",que[j].p.x,que[j].p.y,que[j].val);
//			else printf("Que %d %d %d %d %d %lld\n",i,top>>1,que[j].l,que[j].r,que[j].ord,((i<=(top>>1))?(query(que[j].r-1)-query(que[j].l-1ll)):-((query(que[j].l)-query(que[j].r)))));
			if(!~que[j].ord)update(que[j].l,que[j].val);
			else{
				if(i==(top>>1))ans[que[j].ord]+=(query(que[j].r)-query(que[j].l-1ll));
				else if(i==top)ans[que[j].ord]-=(query(que[j].l)-query(que[j].r-1ll));
				else if(i<=(top>>1))ans[que[j].ord]+=(query(que[j].r-1ll)-query(que[j].l-1ll));
				else ans[que[j].ord]-=(query(que[j].l)-query(que[j].r));
			}
		}
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}