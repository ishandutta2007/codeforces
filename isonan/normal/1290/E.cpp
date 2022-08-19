#include <cstdio>
#include <algorithm>

int n,a[150001];
long long cnt[150001];
namespace Isonan{
	int a[150001],pos[150001];
	struct point{int mx,skdmx,cmx;long long sma,smx;}se[1600001];
	point merge(point a,point b){
		if(a.mx==b.mx)return(point){a.mx,std::max(a.skdmx,b.skdmx),a.cmx+b.cmx,a.sma+b.sma,a.smx+b.smx};
		else if(a.mx<b.mx)std::swap(a,b);
		return (point){a.mx,std::max(a.skdmx,b.mx),a.cmx,a.sma,a.smx};
	}
	int lazy[1600001],add[1600001],val[1600001];
	void pushdown(int x,int y){
		lazy[x]=std::min(lazy[x],y);
		se[x].mx=std::min(se[x].mx,y);
	}
	void addit(int x,int y){
		se[x].smx+=1ll*se[x].cmx*y;
		add[x]+=y;
	}
	void spread(int x){
		if(lazy[x]<0x7f7f7f7f){
			pushdown(x<<1,lazy[x]);
			pushdown(x<<1|1,lazy[x]);
			lazy[x]=0x7f7f7f7f;
		}
		if(add[x]){
			addit(x<<1,add[x]);
			addit(x<<1|1,add[x]);
			add[x]=0;
		}
	}
	void pushup(int root){
		se[root]=merge(se[root<<1],se[root<<1|1]);
		val[root]=val[root<<1]+val[root<<1|1];
	}
	long long cnt0,cnt1,cnt2,calc;
	int c[150001];
	void upd(int ind){for(;ind;ind-=ind&-ind)++c[ind];}
	int query(int ind){if(ind>n)return 0;int tot=0;for(;ind<=n;ind+=ind&-ind)tot+=c[ind];return tot;}
	void update(int root,int l,int r,int e){
		spread(root);
		if(l>e){calc+=val[root];return;}
		if(e>=r){
//			printf("update [%d %d] : %d %d\n",l,r,se[root].mx,se[root].skdmx);
			if(se[root].mx<=e){
				addit(root,1);
				return;
			}
			else if(se[root].skdmx<=e){
//				printf("%d %d\n",se[root].mx,query(se[root].mx));
				cnt0+=se[root].cmx,cnt1+=se[root].smx,cnt2+=se[root].smx-1ll*(query(se[root].mx))*se[root].cmx;pushdown(root,e);
				addit(root,1);
				return;
			}
		}
		update(root<<1,l,(l+r)>>1,e),update(root<<1|1,((l+r)>>1)+1,r,e);
		pushup(root);
	}
	void change(int root,int l,int r,int e,int add){
		spread(root);
		if(l==r){val[root]=1;se[root]=(point){0x7f7f7f7f,0,1,add,add};return;}
		if((l+r)>>1>=e)change(root<<1,l,(l+r)>>1,e,add);
		else change(root<<1|1,((l+r)>>1)+1,r,e,add);
		pushup(root);
	}
	void build(int root,int l,int r){
		val[root]=add[root]=0;
		lazy[root]=0x7f7f7f7f;
		se[root]=(point){0x7f7f7f7f,0,0,0,0};
		if(l==r)return;
		build(root<<1,l,(l+r)>>1);
		build(root<<1|1,((l+r)>>1)+1,r);
	}
	//cnt0:
	//cnt1:\sum 
	//cnt2:\sum 
	void solve(){
		build(1,1,n);
		for(int i=1;i<=n;i++)pos[a[i]]=i,c[i]=0;
		for(int i=1;i<=n;i++){
			calc=cnt0=cnt1=cnt2=0;
			update(1,1,n,pos[i]);
//			printf("%d %d %d %d %d\n",i,cnt0,cnt1,cnt2,calc);
			cnt[i]+=cnt2+1ll*cnt0*calc-cnt1;
			change(1,1,n,pos[i],calc);
			upd(pos[i]);
		}
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)Isonan::a[i]=a[i];
	Isonan::solve();
	for(int i=1;i<=n;i++)Isonan::a[n-i+1]=a[i];
	Isonan::solve();
//	putchar('*');for(int i=1;i<=n;i++)printf("%d ",cnt[i]);putchar('\n');
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
		printf("%lld\n",((1ll*i*(i+1))>>1ll)-cnt[i]);
	}
}