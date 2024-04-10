#include <cstdio>
#include <vector>

std::vector<int>vec[100001];
int n,m,head[100001],nxt[200001],b[200001],k,in[100001],out[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
		if(u>v)vec[v].push_back(u),++out[u],++in[v];
		else vec[u].push_back(v),++in[u],++out[v];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=1ll*in[i]*out[i];
	int q;
	printf("%I64d\n",ans);
	scanf("%d",&q);
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x);
		for(int j=0;j<vec[x].size();j++){
			vec[vec[x][j]].push_back(x);
			ans-=1ll*in[vec[x][j]]*out[vec[x][j]];
			ans-=1ll*in[x]*out[x];
			--out[vec[x][j]],++in[vec[x][j]];
			--in[x],++out[x];
			ans+=1ll*in[vec[x][j]]*out[vec[x][j]];
			ans+=1ll*in[x]*out[x];
		}
		vec[x].clear();
		printf("%I64d\n",ans);
	}
}