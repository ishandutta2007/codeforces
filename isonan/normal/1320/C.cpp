#include <cstdio>
#include <cstring>
#include <algorithm>

struct mon{
	int x,y,z;
}num[200001];
struct equip{
	int a,c;
}a[200001],b[200001];
bool cmp1(mon a,mon b){return a.x<b.x;}
bool cmp2(equip a,equip b){return a.a<b.a;}
int n,m,p;
int se[7000001],v[1000001],lazy[7000001];
void build(int root,int l,int r){
	if(l==r){
		se[root]=-v[l];
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=std::max(se[root<<1],se[root<<1|1]);
}
void pushdown(int root,int x){se[root]+=x,lazy[root]+=x; }
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
} 
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	se[root]=std::max(se[root<<1],se[root<<1|1]);
}
int main(){
	memset(v,0x7f7f7f7f,sizeof v);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].c);
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].a,&b[i].c),v[b[i].a]=std::min(v[b[i].a],b[i].c);
	for(int i=1;i<=p;i++)scanf("%d%d%d",&num[i].x,&num[i].y,&num[i].z);
	std::sort(num+1,num+p+1,cmp1);
	std::sort(a+1,a+n+1,cmp2);
	int now=1; 
	build(1,1,1000000);
	int ans=-0x7f7f7f7f;
//	printf("%d\n",se[1]);
	for(int i=1;i<=n;i++){
//		printf("%d %d\n",num[now].x,a[i].a);
		while(now<=p&&num[now].x<a[i].a){
			add(1,1,1000000,num[now].y+1,1000000,num[now].z);
//			printf("%d %d %d\n",num[now].x,num[now].y,num[now].z);
			++now;
		}
		ans=std::max(ans,se[1]-a[i].c);
	}
	printf("%d\n",ans);
}