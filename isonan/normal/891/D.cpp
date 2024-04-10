#include <cstdio>
#include <vector>
#include <cstring>

int n,head[500001],nxt[1000001],b[1000001],k,size[500001];
long long ans;
struct info{
	int f[2][2];
	info operator+(info a){
		info c;
		memset(c.f,0,sizeof c.f);
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;i+k<2;k++)
					for(int l=0;j+l<2;l++)
						c.f[i+k][j+l]+=f[i][j]*a.f[k][l];
		return c;
	}
	info c(){
		info c;
		c.f[0][0]=f[1][0];
		c.f[0][1]=f[1][1];
		c.f[1][0]=f[0][0];
		c.f[1][1]=f[0][1];
		return c;
	}
	void af(){
		f[1][1]+=f[0][0];
	}
}f[500001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	size[x]=1;
	f[x].f[0][0]=f[x].f[1][1]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			size[x]+=size[b[i]];
			f[x]=f[x]+f[b[i]].c();
//	for(int l=0;l<2;l++,putchar('\n'))
//		for(int j=0;j<2;j++)
//			printf("%d ",f[b[i]].c().f[l][j]);
		}
//	printf("dfs %d\n",x);
//	for(int i=0;i<2;i++,putchar('\n'))
//		for(int j=0;j<2;j++)
//			printf("%d ",f[x].f[i][j]);
}
void dfs2(int x,int F,info T){
//	printf("%d %d %d %d %d\n",x,f[x].f[1][0],f[x].f[1][1],T.f[1][0],T.f[1][1]);
	if(F){
		if(size[x]%2==0){
			if(f[x].f[1][0]&&T.f[1][0])ans+=1ll*size[x]*(n-size[x]);
		}
		else{
			ans+=1ll*f[x].f[1][1]*T.f[1][1];
		}
	}
	(T=T.c()).af();
	std::vector<info>frn,bak;
	std::vector<int>vec;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)vec.push_back(b[i]),frn.push_back(f[b[i]].c()),bak.push_back(f[b[i]].c());
	for(int i=1;i<frn.size();i++)frn[i]=frn[i]+frn[i-1];
	for(int i=bak.size()-2;i>=0;i--)bak[i]=bak[i]+bak[i+1];
//	puts("");
//	for(int i=0;i<2;i++,putchar('\n'))
//		for(int j=0;j<2;j++)
//			printf("%d ",T.f[i][j]);
	for(int i=0;i<vec.size();i++){
		info y=T;
		if(i)y=y+frn[i-1];
		if(i<vec.size()-1)y=y+bak[i+1];
		dfs2(vec[i],x,y);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	dfs2(1,0,(info){0,0,1,0});
	printf("%lld\n",ans);
}