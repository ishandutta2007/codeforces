#include <bits/stdc++.h>

int n,m,head[10001],nxt[20010],b[20010],k=1;
int dep[10001],stk[10001],top;
int f[10001];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
int circ[10001],ct;
bool vis[10001];
int Xor;
int cnt[2][10001],tot;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int d){
	if(ct)return;
	dep[x]=d;
	for(int i=head[x];i;i=nxt[i]){
		if(ct)return;
		if(!dep[b[i]]){
			stk[++top]=i^1;
			dfs(b[i],d+1);
			--top;
		}
		else if(dep[b[i]]%2==dep[x]%2){
//			printf("%d %d\n",b[i],x);
			circ[++ct]=i^1;
			vis[i>>1]=1;
			do{
				circ[++ct]=stk[top];
				vis[stk[top]>>1]=1;
				--top;
			}while(b[stk[top+1]]!=b[i]);
		}
	}
}
void bipart(int x,int c){
	dep[x]=c;
	for(int i=head[x];i;i=nxt[i])
		if(!vis[i>>1]){
			int u=find(x),v=find(b[i]);
//			printf("%d %d\n",b[i],x);
			if(u!=v)f[u]=v;
			if(!~dep[b[i]])bipart(b[i],c^1);
			else if(dep[b[i]]==dep[x]){
				puts("0");
				exit(0);
			}
		}
}
std::vector<int>ans;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	for(int i=1;i<=n;i++)
		if(!dep[i]){
			dfs(i,1);
			if(ct)break;
		}
	if(!ct){
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",i);
		return 0;
	}
//	for(int i=1;i<=ct;i++)printf("%d %d\n",b[circ[i]],b[circ[i]^1]);putchar('\n');
	memset(dep,-1,sizeof dep);
	for(int i=1;i<=n;i++)
		if(!~dep[i])bipart(i,0);
	for(int i=1;i<=ct;i++){
		++cnt[(i&1)^1^dep[b[circ[i]]]][find(b[circ[i]])];
	}
	for(int i=1;i<=n;i++)
		tot+=(cnt[0][i]&&cnt[1][i]);
//	for(int i=1;i<=n;i++)printf("%d %d %d\n",i,find(i),dep[i]);
	for(int i=1;i<=ct;i++){
		if(!tot)ans.push_back(circ[i]);
		int u=find(b[circ[i]]);
		tot-=(cnt[0][u]&&cnt[1][u]);
		--cnt[Xor^dep[b[circ[i]]]][u];
		Xor^=1;
		++cnt[Xor^dep[b[circ[i]]]][u];
		tot+=(cnt[0][u]&&cnt[1][u]);
	}
	std::sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]>>1);
}