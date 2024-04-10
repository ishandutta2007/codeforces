#include <cstdio>
#include <algorithm>

int t,n,head[200001],nxt[400001],b[400001],k,v[400001],size[400001];
long long ans1,ans2;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs1(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[b[i]]%2==1)ans1+=v[i];
			ans2+=1ll*v[i]*std::min(size[b[i]],n-size[b[i]]);
		}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		n<<=1;
		for(int i=1;i<=n;i++)head[i]=0;
		k=0;
		ans1=ans2=0;
		for(int i=1,u,v,val;i<n;i++)scanf("%d%d%d",&u,&v,&val),push(u,v,val),push(v,u,val);
		dfs1(1,0);
		printf("%lld %lld\n",ans1,ans2);
	}
}