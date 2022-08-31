#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,K,q[200001],h,T;
int head[200001],nxt[400001],b[400001],k,d[200001],f[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)head[i]=d[i]=0;
		k=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&K);
			for(int j=1;j<=K;++j){
				int r;
				scanf("%d",&r);
				push(r,i);
				++d[i];
			}
		}
		h=t=0;
		for(int i=1;i<=n;++i)f[i]=0;
		for(int i=1;i<=n;++i)if(!d[i])q[++t]=i,f[i]=1;
		while(h<t){
			++h;
			for(int i=head[q[h]];i;i=nxt[i]){
				if(b[i]>q[h])f[b[i]]=std::max(f[b[i]],f[q[h]]);
				else f[b[i]]=std::max(f[b[i]],f[q[h]]+1);
				if(!--d[b[i]])q[++t]=b[i];
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)ans=std::max(ans,f[i]);
		if(ans==0x7f7f7f7f||t<n)puts("-1");
		else printf("%d\n",ans);
	}
}