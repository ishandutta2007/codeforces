#include <cstdio>

int n,p[300001],pos[300001],lazy[3000001];
struct info{
	int p[2],cnt[2];
	info(){
		p[0]=p[1]=0x7f7f7f7f;
		cnt[0]=cnt[1]=0;
	}
	void add(int P,int C){
		if(!C)return;
		if(P==p[0])cnt[0]+=C;
		else if(P==p[1])cnt[1]+=C;
		else if(P<p[0])cnt[1]=cnt[0],p[1]=p[0],cnt[0]=C,p[0]=P;
		else if(P<p[1])cnt[1]=C,p[1]=P;
	}
}se[3000001];
void pushdown(int x,int y){
	se[x].p[0]+=y;
	se[x].p[1]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
info merge(info a,info b){
	a.add(b.p[0],b.cnt[0]);
	a.add(b.p[1],b.cnt[1]);
	return a;
}
void pushup(int x){se[x]=merge(se[x<<1],se[x<<1|1]);}
void update(int root,int l,int r,int el,int er,int x){
//	if(root==1)printf("update %d %d %d\n",el,er,x);
	if(el>r||er<l)return;
	if(el<=l&&er>=r)return pushdown(root,x);
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
info query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return info();
	if(el<=l&&er>=r)return se[root];
	spread(root);
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void build(int root,int l,int r){
	if(l==r){
		se[root].p[0]=0;
		se[root].cnt[0]=1;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i),pos[p[i]]=i;
	build(1,1,n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		update(1,1,n,1,i,1);
		if(p[pos[i]-1]<i)update(1,1,n,1,p[pos[i]-1],-1);
		if(pos[i]<n&&p[pos[i]+1]<i)update(1,1,n,1,p[pos[i]+1],-1);
		auto now=query(1,1,n,1,i-1);
		if(now.p[0]<=2)ans+=now.cnt[0];
		if(now.p[1]<=2)ans+=now.cnt[1];
//		printf("%d %d\n",i,ans);
	}
	printf("%lld\n",ans);
}