#include <cstdio>
#include <algorithm>
using namespace std;

int n,c,a[500010],nowans,cnt[500010];
struct point{
	int lmx,rmx,tot,tmx;
	point(int a=0,int b=0,int c=0,int d=0){
		lmx=a;
		rmx=b;
		tot=c;
		tmx=d;
	}
	void set(int n=0){
		lmx=rmx=tot=tmx=n;
	}
}se[8000001];
struct num{
	int val,orig;
}NI[500010];
bool cmp(num a,num b){
	return a.val<b.val;
}
int max(int a,int b){
	return a>b?a:b;
}
point merge(point a,point b){
	return (point){max(a.lmx,a.tot+b.lmx),max(b.rmx,b.tot+a.rmx),a.tot+b.tot,max(max(a.tmx,b.tmx),a.rmx+b.lmx)};
}
void update(int root,int l,int r,int e,int x){
	if(l==r){
		se[root].set(x);
		return;
	}
	if(((l+r)>>1)>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
void build(int root,int l,int r){
	se[root].set(0);
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
int main(){
	scanf("%d%d",&n,&c);
	int top=0,tot=0,ans=0;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==c)update(1,1,n,i,-1),tot++;
		else NI[++top]=(num){a[i],i};
	}
	sort(NI+1,NI+top+1,cmp);
	int h=1,t=0;
	for(t=1;t<=top;t++){
		h=t;
		while(NI[t].val==NI[h].val&&t<=top)update(1,1,n,NI[t].orig,1),t++;
		ans=max(ans,se[1].tmx);
		for(int j=h;j<t;j++)update(1,1,n,NI[j].orig,0);
		t--;
	}
	printf("%d",ans+tot);
}