#include <cstdio>
#include <random>
#include <cstring>
#define int long long

int lson[70010],rson[70010],slope[70010],rs[70010],root,key[70010],lazy[3][70010],pri[70010];
int tem[3][70010],top;
int n,a[70001],l[70001],r[70001],ans=1e18;
void pushdown(int x,int y,int t){
	if(!x)return;
	if(t==0)key[x]+=y;
	else if(t==1)slope[x]+=key[x]*y,rs[x]+=y;
	else slope[x]+=y;
	if(t==0)lazy[2][x]-=lazy[1][x]*y;
	lazy[t][x]+=y;
}
void spread(int x){
	for(int i=0;i<3;i++)
		if(lazy[i][x])pushdown(lson[x],lazy[i][x],i),pushdown(rson[x],lazy[i][x],i),lazy[i][x]=0;
}
void splitk(int now,int &x,int &y,int v){
	spread(now);
	if(!now)x=y=0;
	else{
		if(key[now]<=v)x=now,splitk(rson[now],rson[now],y,v);
		else y=now,splitk(lson[now],x,lson[now],v);
	}
}
void splits(int now,int &x,int &y,int v){
	spread(now);
	if(!now)x=y=0;
	else{
		if(rs[now]<=v)x=now,splits(rson[now],rson[now],y,v);
		else y=now,splits(lson[now],x,lson[now],v);
	}
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	spread(a),spread(b);
	if(pri[a]<pri[b]){
		rson[a]=merge(rson[a],b);
		return a;
	}
	else{
		lson[b]=merge(a,lson[b]);
		return b;
	}
}
int getr(int x){
	while(rson[x])spread(x),x=rson[x];
	return x;
}
int getl(int x){
	while(lson[x])spread(x),x=lson[x];
	return x;
}
void dfs(int x){
	if(!x)return;
	spread(x);
	dfs(lson[x]);
	++top;
	tem[0][top]=key[x];
	tem[1][top]=slope[x];
	tem[2][top]=rs[x];
	dfs(rson[x]);
}
long long f(long long x){
	long long L=x,R=x;
	memset(lson,0,sizeof lson);
	memset(rson,0,sizeof rson);
	memset(key,0,sizeof key);
	memset(slope,0,sizeof slope);
	memset(rs,0,sizeof rs);
	memset(lazy,0,sizeof lazy);
	root=n<<1|1;
	key[n<<1|1]=x;
//		top=0;
//		dfs(root);
//		for(int i=1;i<=top;i++)printf("(%lld %lld)",tem[0][i],tem[1][i]);putchar('\n');
	for(int i=1;i<n;i++){
//		printf("*%lld %lld\n",key[getl(root)],key[getr(root)]);
		pushdown(root,r[i]-a[i],0);
//			top=0;
//			dfs(root);
//			for(int i=1;i<=top;i++)printf("(%lld %lld %lld)",tem[0][i],tem[1][i],tem[2][i]);putchar('\n');
//			printf("%lld %lld\n",L,R);
		int t1,t2;
		splits(root,t1,t2,-1);
		key[(i<<1)-1]=key[t2?getl(t2):getr(t1)];
		slope[(i<<1)-1]=slope[t2?getl(t2):getr(t1)];
		rs[(i<<1)-1]=0;
		if(!t2)t2=(i<<1)-1;
		else t1=merge(t1,(i<<1)-1);
//		if(t2){
//			top=0;
//			dfs(t2);
//			for(int i=1;i<=top;i++)printf("(%lld %lld)",tem[0][i],tem[1][i]);putchar('\n');
//			printf("%lld %lld\n",L,R);
//			top=0;
//			dfs(t1);
//			for(int i=1;i<=top;i++)printf("(%lld %lld)",tem[0][i],tem[1][i]);putchar('\n');
//			printf("%lld %lld\n",L,R);
//		}
		pushdown(t1,-(r[i]-l[i]),0);
		root=merge(t1,t2);
//		printf("*%lld %lld\n",key[getl(root)],key[getr(root)]);
		splitk(root,t1,t2,-1);
		L+=l[i]-a[i];
		R+=r[i]-a[i];
		if(L*R<0){
			int u=getr(t1),v=getl(t2);
			slope[i<<1]=slope[u]+((slope[v]-slope[u])/(key[v]-key[u]))*(-key[u]);
			rs[i<<1]=rs[u];
//			printf("%lld %lld %lld %lld %lld\n",slope[u],key[u],slope[v],key[v],slope[i<<1]);
			t2=merge(i<<1,t2);
		}
		pushdown(t1,-1,1);
		pushdown(t2,1,1);
		root=merge(t1,t2);
//		printf("%d %d\n",L,R);
	}
	top=0;
	dfs(root);
	int ql=a[n]-r[n]+x,qr=a[n]-l[n]+x,fin=1e18;
//	printf("%lld %lld\n",ql,qr);
	for(int i=1;i<top;i++){
		int l=std::max(tem[0][i],ql),r=std::min(tem[0][i+1],qr);
		if(l<=r){
			if(tem[0][i]==tem[0][i+1]){
				fin=std::min(fin,tem[1][i]);
				continue;
			}
			fin=std::min(fin,tem[1][i]+((tem[1][i+1]-tem[1][i])/(tem[0][i+1]-tem[0][i]))*(l-tem[0][i]));
			fin=std::min(fin,tem[1][i]+((tem[1][i+1]-tem[1][i])/(tem[0][i+1]-tem[0][i]))*(r-tem[0][i]));
		}
	}
	fin+=abs(x);
	ans=std::min(ans,fin);
//	printf("f %lld %lld\n",x,fin);
	return fin;
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	std::mt19937 rand(19360817);
	for(int i=1;i<=(n<<1)+1;i++)pri[i]=rand();
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",a+i,l+i,r+i);
//	f(-1);
//	return 0;
	int l=-n*35000,r=n*35000,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(f(mid)<=f(mid+1))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
}