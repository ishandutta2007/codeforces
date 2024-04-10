#include <cstdio>
#include <algorithm>

int head[200001],nxt[400001],b[400001],k=1,d[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int n;
int l[100001],r[100001],o[200001],cnt;
int ans[200001],pre;
bool vis[200001];
void dfs(int x){
	while(vis[head[x]>>1])head[x]=nxt[head[x]];
	for(int i=head[x];i;i=nxt[i]){
		vis[i>>1]=1;
		dfs(b[i]);
		ans[i>>1]=(x<b[i]);
		while(vis[nxt[i]>>1])nxt[i]=nxt[nxt[i]];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",l+i,r+i);
		l[i]<<=1;
		(r[i]<<=1)|=1;
		o[++cnt]=l[i];
		o[++cnt]=r[i];
	}
	std::sort(o+1,o+cnt+1);
	cnt=std::unique(o+1,o+cnt+1)-o-1;
	for(int i=1;i<=n;++i){
		l[i]=std::lower_bound(o+1,o+cnt+1,l[i])-o;
		r[i]=std::lower_bound(o+1,o+cnt+1,r[i])-o;
		push(l[i],r[i]);
		push(r[i],l[i]);
		d[l[i]]^=1,d[r[i]]^=1;
	}
	for(int i=1,l=0;i<=cnt;++i)
		if(d[i]){
			if(l){
				push(i,l);
				push(l,i);
				l=0;
			}
			else l=i;
		}
	for(int i=1;i<=cnt;++i)dfs(i);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}