#include <algorithm> 
#include <cstdio>
#include <map>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int inv2=qsm(2,P-2),inv6=qsm(6,P-2);
int n,t,time[100001],top,orig[110];
std::pair<int,int>p[101];
std::map<int,int>map;
struct ope{
	int l,r,t,ord;
}num[110];
bool cmp(ope a,ope b){return (a.t<b.t)||(a.t==b.t&&a.ord<b.ord);}
int abs(int x){return x<0?-x:x;}
int se[200001],mn[200001],lazy[200001];
void build(int root,int l,int r){
	mn[root]=lazy[root]=0,se[root]=orig[r+1]-orig[l];
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
void pushdown(int x,int y){
	mn[x]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
void pushup(int x){
	mn[x]=std::min(mn[x<<1],mn[x<<1|1]);
	se[x]=0;
	if(mn[x<<1]==mn[x])se[x]+=se[x<<1];
	if(mn[x<<1|1]==mn[x])se[x]+=se[x<<1|1];
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
int f(int x){
	if(map.count(x))return map[x];
	for(int i=1;i<=n;i++)orig[(i<<1)-1]=p[i].first-x,orig[i<<1]=p[i].first+x+1;
	std::sort(orig+1,orig+(n<<1)+1);
	int lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
//	for(int i=1;i<=lim;i++)printf("%d ",orig[i]);putchar('\n');
	for(int i=1;i<=n;i++){
		int l=std::lower_bound(orig+1,orig+lim+1,p[i].first-x)-orig,
			r=std::lower_bound(orig+1,orig+lim+1,p[i].first+x+1)-orig-1;
		num[(i<<1)-1]=(ope){l,r,p[i].second-x,1};
		num[i<<1]=(ope){l,r,p[i].second+x+1,-1};
	}
	std::sort(num+1,num+(n<<1)+1,cmp);
	build(1,1,lim-1);
	int ans=0;
	for(int i=1;i<=n<<1;i++){
//		printf("update %d %d %d\n",num[i].l,num[i].r,num[i].ord);
//		printf("%d %d\n",se[1],mn[1]);
		update(1,1,lim-1,num[i].l,num[i].r,num[i].ord);
		ans=add(ans,mul(sub(orig[lim]-orig[1],mn[1]?0:se[1]),num[i+1].t-num[i].t));
//		printf("%d\n",ans);
	}
//	printf("f(%d)=%d\n",x,ans);
	return map[x]=ans;
}
int sum1(int x){return mul(mul(1+x,x),inv2);}
int sum2(int x){return mul(mul(x,x+1),mul(2*x+1,inv6));}
int solve(int l,int r){
	if(l>r)return 0;
	int ans=0;
	ans=mul(sub(f(l),f(l-1)),l);
	++l;
	if(r-l+1<3){
		for(int i=l;i<=r;i++)ans=add(ans,mul(sub(f(i),f(i-1)),i));
//		printf("%d\n",ans);
		return ans;
	}
	int f1=sub(f(l),f(l-1)),f2=sub(f(l+1),f(l)),k=sub(f2,f1),b=sub(f1,mul(k,l));
	return add(ans,add(mul(k,sub(sum2(r),sum2(l-1))),mul(b,sub(sum1(r),sum1(l-1)))));
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	printf("%d\n",mul(8,sum2(100000000))); 
	scanf("%d%d",&n,&t);
	time[++top]=t;
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
//	return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			time[++top]=std::max((abs(p[i].first-p[j].first)-1)>>1,(abs(p[i].second-p[j].second)-1)>>1);
		}
	time[++top]=0;
	std::sort(time+1,time+top+1);
	int ans=0;
	for(int i=1;i<=top;i++){
		if(time[i]>=t)break;
		ans=add(ans,solve(time[i]+1,time[i+1]));
	}
	printf("%d",ans);
}