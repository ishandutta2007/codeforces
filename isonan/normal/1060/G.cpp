#include <cstdio>
#include <algorithm>

int n,m,top,ttop;
long long a[100001];
long long ans[100001];
struct que{
	long long x,k,ord;
}num[100001],Que[100001];
long long lazy[1000001],se[1000001];
void pushdown(int root,long long y){lazy[root]+=y,se[root]+=y;}
void spread(int root){
	if(lazy[root]){
		pushdown(root<<1,lazy[root]);
		pushdown(root<<1|1,lazy[root]);
		lazy[root]=0;
	}
}
void pushup(int root){se[root]=std::min(se[root<<1],se[root<<1|1]);}
void build(int root,int l,int r){
	lazy[root]=0;
	if(l==r){
		se[root]=1e15+1ll*l;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void update(int root,int l,int r,int el,int er,long long x){
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
int query(int root,int l,int r,long long x){
	spread(root);
	if(l==r)return l;
	if(se[root<<1|1]<=x)return query(root<<1|1,((l+r)>>1)+1,r,x);
	else return query(root<<1,l,(l+r)>>1,x);
}
long long get(int root,int l,int r,int e){
	spread(root);
	if(l==r)return se[root];
	if((l+r)>>1>=e)return get(root<<1,l,(l+r)>>1,e);
	else return get(root<<1|1,((l+r)>>1)+1,r,e);
}
void clear(int &now){
	while(se[1]<=a[now]){
		int pos=query(1,1,n,a[now]);
		update(1,1,n,pos,pos,1e16);
		update(1,1,n,pos+1,n,-1);
		--now;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++){
		++top;
		scanf("%lld%lld",&num[top].x,&num[top].k);
		if(num[top].x<a[1])ans[i]=num[top--].x;
		else num[top].ord=i;
	}
	build(1,1,n);
	std::sort(num+1,num+top+1,[&](que a,que b){return a.x>b.x;});
	long long time=0;
	for(int i=1,now=n;i<=top;i++){
		while(se[1]>num[i].x){
			clear(now);
			if(a[now]>num[i].x){
				time+=(se[1]-a[now]+now-1)/now;
				update(1,1,n,1,n,-1ll*((se[1]-a[now]+now-1)/now)*now);
			}
			else{
//				putchar('*');
				time+=(se[1]-num[i].x+now-1)/now;
//				printf("%lld ",se[1]-1ll*((se[1]-num[i].x+now-1)/now)*now);
				update(1,1,n,1,n,-1ll*((se[1]-num[i].x+now-1)/now)*now);
//				printf("%lld ",se[1]);
			}
//			printf("%lld\n",se[1]);
		}
		Que[++ttop]=(que){query(1,1,n,num[i].x),time-num[i].k,num[i].ord};
	}
//	return 0;
	build(1,1,n);
	std::sort(Que+1,Que+ttop+1,[&](que a,que b){return a.k<b.k;});
	time=0;
	for(int i=1,now=n;i<=ttop;i++){
//		printf("%lld ",Que[i].k);
		while(time<Que[i].k){
//			printf("%lld %d %lld\n",time,now,Que[i].k);
			clear(now);
			if(time+(se[1]-a[now]+now-1)/now<Que[i].k){
				time+=(se[1]-a[now]+now-1)/now;
				update(1,1,n,1,n,-1ll*((se[1]-a[now]+now-1)/now)*now);
			}
			else{
				update(1,1,n,1,n,-1ll*(Que[i].k-time)*now);
				time=Que[i].k;
			}
		}
//		putchar('*');
		ans[Que[i].ord]=get(1,1,n,Que[i].x);
//		putchar('*');
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}