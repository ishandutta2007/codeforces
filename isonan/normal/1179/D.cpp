#include <cstdio>
#include <algorithm>

long long f[500001],size[500001],ans,n,top,from[500001],skdmx[500001],skdfrom[500001],k;
int head[500001],nxt[1000001],b[1000001],q[1000001],t,in[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
struct point{
	long long siz,f,k,b;
}num[500001];
bool cmp(point a,point b){
	return (a.k>b.k)||(a.k==b.k&&a.b>b.b);
}
long long C(long long x){
	return (x*(x-1))>>1;
}
void getans(int x,int F){
	f[x]=n*n;
	size[x]=1;
	int start=top;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			getans(b[i],x);
			size[x]+=size[b[i]];
			num[++top]=(point){size[b[i]],f[b[i]],size[b[i]],size[b[i]]*size[b[i]]+size[b[i]]+2ll*f[b[i]]};
		}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)
			f[x]=std::min(f[x],f[b[i]]+C(size[x]-size[b[i]]));
	std::sort(num+start+1,num+top+1,cmp);
	t=0;
	for(int i=start+1;i<=top;i++){
		if(t){
			int l=2,r=t,mid,ans1=1;
			long long tem=-2ll*(n-num[i].siz);
			while(l<=r){
				mid=(l+r)>>1;
				if(in[mid]>=tem)ans1=mid,r=mid-1;
				else l=mid+1;
			}
			if(ans1)ans=std::min(ans,C(n-num[i].siz-num[q[ans1]].siz)+num[q[ans1]].f+num[i].f);
		}
		while(t&&num[q[t]].k==num[i].k)--t;
		while(t>1&&in[t]>=(num[q[t-1]].b-num[i].b+num[i].k-num[q[t-1]].k-1)/(num[i].k-num[q[t-1]].k))--t;
		q[++t]=i;
		in[t]=(num[q[t-1]].b-num[i].b+num[i].k-num[q[t-1]].k-1)/(num[i].k-num[q[t-1]].k);
	}
	if(f[x]==n*n)f[x]=C(size[x]);
	ans=std::min(ans,f[x]+C(n-size[x]));
	top=start;
}
int main(){
	scanf("%I64d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	ans=n*n;
	getans(1,0);
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	printf("%I64d\n",C(n)*2-ans);
}