#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

int n,C,orig[600010],top,stk[300010],all,Add[300010],One[300010],cost[600010],ctop;
struct info{
	int mx,ord,skdmx;
}c[3000010];
info merge(info a,info b){
	info c;
	if(a.mx>b.mx)c=a,c.skdmx=std::max(c.skdmx,b.mx);
	else c=b,c.skdmx=std::max(c.skdmx,a.mx);
	return c;
}
void build(int root,int l,int r){
	c[root]=(info){-0x7f7f7f7f,0,-0x7f7f7f7f};
//	if(root>1000000)printf("%d %d %d\n",root,l,r);
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
void update(int root,int l,int r,int e,info x){
	if(l==r){
		c[root]=x;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	c[root]=merge(c[root<<1],c[root<<1|1]);
}
info query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (info){-0x7f7f7f7f,0,-0x7f7f7f7f};
	if(el<=l&&er>=r)return c[root];
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
bool Del[300010];
long long f[600010],g[600010];
struct line{
	int l,r,c;
}num[300001];
std::vector<int>add[600010],del[600010];
bool cmp(line a,line b){return (a.r<b.r)||(a.r==b.r&&a.l<b.l);}
int main(){
	scanf("%d%d",&n,&C);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&num[i].l,&num[i].r,&num[i].c),orig[++top]=num[i].l,orig[++top]=num[i].r,cost[++ctop]=num[i].c;
	cost[++ctop]=0;
	std::sort(cost+1,cost+ctop+1);
	ctop=std::unique(cost+1,cost+ctop+1)-cost-1;
	build(1,1,ctop);
	orig[++top]=0;
	orig[++top]=0x7f7f7f7f;
	std::sort(orig+1,orig+top+1);
	top=std::unique(orig+1,orig+top+1)-orig-1;
	for(int i=1;i<=n;i++)num[i].l=std::lower_bound(orig+1,orig+top+1,num[i].l)-orig,num[i].r=std::lower_bound(orig+1,orig+top+1,num[i].r)-orig-1;
	for(int i=1;i<=n;i++)add[num[i].l].push_back(i),del[num[i].r].push_back(i);
	g[0]=-1e18;
	for(int i=1,cnt=0,last1=-1,last2=-1,Sum=0,empty=0;i<=top;i++){
		f[i]=std::max(f[i-1],g[i-1]+orig[i]-1);
//		printf("%d\n",f[i-1]);
		g[i]=-1e18;
		for(int j=0;j<add[i].size();j++)
			stk[++all]=add[i][j],++cnt;//,printf("add %d\n",add[i][j]);
//		printf("interval %d %d(%d)\n",i,cnt,One[8]);
//		if(cnt&&cnt<=2){
//			while(Del[stk[all]])--all;
//			printf("%d ",stk[all]);
//		}
//		if(cnt==2){
//			int p1=stk[all];
//			--all;
//			while(Del[stk[all]])--all;
////			printf("%d ",stk[all]);
////			printf("(%d)",num[p1].c+num[stk[all]].c);
//			stk[++all]=p1;
//		}
//		putchar('\n');
//		printf("%d %d %d\n",i,f[i],empty);
		if(!cnt)g[i]=std::max(g[i],f[i]-orig[i]+1),empty+=orig[i+1]-orig[i];
		else if(cnt==1){
			while(Del[stk[all]])--all;
			if(num[stk[all]].c<=C){
				Add[stk[all]]+=orig[i+1]-orig[i];
				g[i]=std::max(g[i],1ll*empty+1ll*Add[stk[all]]+1ll*One[stk[all]]-1ll*orig[i+1]+1);
				auto now=query(1,1,ctop,1,std::upper_bound(cost+1,cost+ctop+1,C-num[stk[all]].c)-cost-1);
				g[i]=std::max(g[i],1ll*empty+1ll*Add[stk[all]]+1ll*(now.ord==stk[all]?now.skdmx:now.mx)-1ll*orig[i+1]+1);
				update(1,1,ctop,std::lower_bound(cost+1,cost+ctop+1,num[stk[all]].c)-cost,(info){Add[stk[all]],stk[all],-0x7f7f7f7f});
//				printf("push %d %d\n",stk[all],Add[stk[all]]);
			}
		}
		else if(cnt==2){
			while(Del[stk[all]])--all;
			int p1=stk[all];
			--all;
			while(Del[stk[all]])--all;
			int p2=stk[all];
			stk[++all]=p1;
			if(num[p1].c+num[p2].c<=C){
				if(last1!=p1||last2!=p2)Sum=0,last1=p1,last2=p2;
				Sum+=orig[i+1]-orig[i];
				g[i]=std::max(g[i],1ll*empty+Sum+Add[p1]+Add[p2]-orig[i+1]+1);
				One[p2]=std::max(One[p2],Sum+Add[p1]);
				One[p1]=std::max(One[p1],Sum+Add[p2]);
			}
		}
		for(int j=0;j<del[i].size();j++)
			Del[del[i][j]]=1,--cnt;//,printf("del %d\n",del[i][j]);
	}
//	for(int i=1;i<=top;i++)printf("%d %d %d %d %d\n",i,orig[i],f[i],g[i],g[i]+orig[i+1]-1);
	int m;
	scanf("%d",&m);
	for(int i=1,k;i<=m;i++){
		scanf("%d",&k);
		int l=1,r=top-1,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(std::max(f[mid],g[mid]+1ll*orig[mid+1]-1)>=1ll*k)ans=mid,r=mid-1;
			else l=mid+1;
		}
//		printf("%d ",g[top-1]+orig[top]-1);
//		printf("%d %d\n",ans,orig[ans]);
		printf("%lld\n",std::max(1ll*orig[ans],1ll*k-1ll*g[ans])+1ll);
	}
}