#include <cstdio>
#include <algorithm>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;} 
int n,orig[100001],a[100001],lim,pre[100001],nxt[100001],last[100001];
int stk[2][100001],top[2];
int siz[1000001],mn[1000001],mx[1000001],len[1000001],se[2][1000001];
int lazy[2][1000001];
void build(int root,int l,int r){
	siz[root]=r-l+1;
	if(l==r){
		len[root]=l;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	len[root]=add(len[root<<1],len[root<<1|1]);
}
void pushdown(int x,int y,int type){
	if(type==0){
		mx[x]=mul(siz[x],y);
		se[0][x]=mul(len[x],y);
		se[1][x]=mul(mn[x],y);
	}
	else{
		mn[x]=mul(siz[x],y);
		se[1][x]=mul(mx[x],y);
	}
	lazy[type][x]=y;
}
void spread(int x){
	for(int t=0;t<2;t++){
		if(lazy[t][x])pushdown(x<<1,lazy[t][x],t),pushdown(x<<1|1,lazy[t][x],t);
		lazy[t][x]=0;
	}
}
void pushup(int x){
	se[0][x]=add(se[0][x<<1],se[0][x<<1|1]);
	se[1][x]=add(se[1][x<<1],se[1][x<<1|1]);
	mn[x]=add(mn[x<<1],mn[x<<1|1]);
	mx[x]=add(mx[x<<1],mx[x<<1|1]);
}
void update(int root,int l,int r,int el,int er,int x,int t){
//	if(root==1)printf("update %d %d %d %d\n",el,er,x,t);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x,t);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x,t);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x,t);
	pushup(root);
}
int query(int root,int l,int r,int el,int er){
	spread(root);
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return sub(sub(se[0][root],se[1][root]),mul(sub(len[root],mn[root]),er));
	return add(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),orig[i]=a[i];
	std::sort(orig+1,orig+n+1);
	lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(orig+1,orig+lim+1,a[i])-orig;
	for(int i=1;i<=n;i++)pre[i]=last[a[i]],last[a[i]]=i;
	for(int i=1;i<=lim;i++)last[i]=n+1;
	for(int i=n;i;i--)nxt[i]=last[a[i]],last[a[i]]=i;
	long long ans=0;
	build(1,1,n);
	for(int i=1,l=1;i<=n;i++){
//		printf("%d %d\n",pre[i],nxt[i]);
		while(top[0]&&nxt[stk[0][top[0]]]>nxt[i])--top[0];
		update(1,1,n,stk[0][top[0]]+1,i,nxt[i]-1,0);
		stk[0][++top[0]]=i;
		while(top[1]&&pre[stk[1][top[1]]]<pre[i])--top[1];
		update(1,1,n,stk[1][top[1]]+1,i,pre[i]+1,1);
		stk[1][++top[1]]=i;
		l=std::max(l,pre[i]+1);
		ans+=query(1,1,n,l,i);
	}
	printf("%lld\n",ans%P);
}