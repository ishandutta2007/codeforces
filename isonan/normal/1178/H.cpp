#include <cstdio>
#include <cstring>
#include <algorithm>

int head[17601],nxt[200001],b[200001],v[200001],c[200001],k;
int dis[100001],q[2000001],h,t,S,T,n,A[4401],B[4401],pre[100001],flow[100001],cnt[100001];
long long mx[100001],Val[100001];
long long orig[100001];
bool inq[100001];
void push(int s,int t,int val,int cost){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
	c[k]=cost;
}
void link(int s,int t,int val,int cost){
	push(s,t,val,cost);
	push(t,s,0,-cost);
}
bool spfa(){
	for(int i=S;i<=T;i++)dis[i]=0x7f7f7f7f,inq[i]=0;
	dis[S]=0,flow[S]=0x7f7f7f7f;
	h=t=0;
	q[++t]=S;
	inq[S]=1;
	while(h<t){
		inq[q[++h]]=0;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]>dis[q[h]]+c[i]){
				dis[b[i]]=dis[q[h]]+c[i];
				pre[b[i]]=i;
				flow[b[i]]=std::min(flow[q[h]],v[i]);
				if(!inq[b[i]])inq[b[i]]=1,q[++t]=b[i];
			}
	}
	return dis[T]!=0x7f7f7f7f;
}
int f(int u){
	for(int i=S;i<=T;i++)head[i]=0;
	k=1;
	for(int i=1;i<=(n<<1);i++)orig[i]=B[i];
	std::sort(orig+1,orig+(n<<1)+1);
	int lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
	for(int i=1;i<=(n<<1);i++){
		if(i<=n)link(S,i,1,0);
		int v=std::lower_bound(orig+1,orig+lim+1,B[i])-orig+(n<<1);
		link(i,v,0x7f7f7f7f,1);
		link(v,i,0x7f7f7f7f,0);
		link(v,i+(n*6),0x7f7f7f7f,0);
	}
	for(int i=lim;i>1;i--)link(i+(n<<1),i-1+(n<<1),0x7f7f7f7f,0);
	for(int i=1;i<=(n<<1);i++)orig[i]=1ll*u*A[i]+1ll*B[i];
	std::sort(orig+1,orig+(n<<1)+1);
	lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
	for(int i=1;i<=(n<<1);i++){
		if(i>n)link(i+(n*6),T,1,0);
		int v=std::lower_bound(orig+1,orig+lim+1,1ll*u*A[i]+1ll*B[i])-orig+(n<<2);
		link(i,v,0x7f7f7f7f,1);
		link(v,i+(n*6),0x7f7f7f7f,0);
	}
	for(int i=lim;i>1;i--)link(i+(n<<2),i-1+(n<<2),0x7f7f7f7f,0);
	long long ans=0,ans2=0;
	while(spfa()){
		int tem=T;
		while(tem!=S){
			--v[pre[tem]];
			++v[pre[tem]^1];
			tem=b[pre[tem]^1];
		}
		ans+=flow[T];
		ans2+=1ll*flow[T]*dis[T];
	}
	if(ans<n)return -1;
	else return ans2;
}
bool judge(int u){
	for(int i=1;i<=(n<<1);i++)orig[i]=B[i];
	std::sort(orig+1,orig+(n<<1)+1);
	int lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
	for(int i=1;i<=lim;i++)mx[i]=-0x7f7f7f7f;
	for(int i=1;i<=(n<<1);i++){
		int v=std::lower_bound(orig+1,orig+lim+1,B[i])-orig;
//		printf("judge %d %d %lld %d\n",u,i,1ll*u*A[i]+1ll*B[i],v);
		mx[v]=std::max(mx[v],1ll*u*A[i]+1ll*B[i]);
	}
	for(int i=1;i<=lim;i++)mx[i]=std::max(mx[i],mx[i-1]);
	for(int i=1;i<=(n<<1);i++)Val[i]=(i<=n)?mx[std::lower_bound(orig+1,orig+lim+1,B[i])-orig]:(1ll*u*A[i]+B[i]);
	for(int i=1;i<=(n<<1);i++)orig[i]=Val[i];
//	for(int i=1;i<=(n<<1);i++)printf("%lld ",Val[i]);putchar('\n');
	std::sort(orig+1,orig+(n<<1)+1);
	lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
	for(int i=1;i<=lim;i++)cnt[i]=0;
	for(int i=1;i<=(n<<1);i++)cnt[std::lower_bound(orig+1,orig+lim+1,Val[i])-orig]+=(i<=n?-1:1);
	for(int i=1;i<=lim;i++){
		cnt[i]+=cnt[i-1];
//		printf("%d %d %lld\n",i,cnt[i],orig[i]);
		if(cnt[i]<0)return 0;
	}
	return 1;
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	S=0,T=n*8+1;
	for(int i=1;i<=(n<<1);i++)scanf("%d%d",A+i,B+i);
	int l=0,r=1000000000,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
//	if(A[1]==501)return 0;
	if(~ans)printf(" %d",f(ans));
}