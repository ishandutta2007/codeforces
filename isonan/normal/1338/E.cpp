#include <cstdio>
#include <vector>

int n;
bool con[8001][8001];
int get(){
	char ch=getchar();
	while((ch<'0'||ch>'9')&&(ch<'A'||ch>'F'))ch=getchar();
	return (ch>='0'&&ch<='9')?(ch-'0'):(ch-'A'+10);
}
int ans[8001],low[8001],dfn[8001],now,stk[8010],top,S,size[8001],d[8001];
bool instack[8001],vis[8001];
std::vector<int>vec[8001];
void tarjan(int x){
	low[x]=dfn[x]=++now;
	instack[x]=1;
	stk[++top]=x;
	for(int i=1;i<=n;i++)
		if(con[x][i])
			if(!dfn[i])tarjan(i),low[x]=std::min(low[x],low[i]);
			else if(instack[i])low[x]=std::min(low[x],dfn[i]);
	if(low[x]==dfn[x]){
		++S;
		do{
			vec[S].push_back(stk[top]);
			ans[stk[top]]=S;
			instack[stk[top--]]=0;
		}while(stk[top+1]!=x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j+=4){
			int stat=get();
			con[i][j+1]=(stat&8)!=0;
			con[i][j+2]=(stat&4)!=0;
			con[i][j+3]=(stat&2)!=0;
			con[i][j+4]=(stat&1)!=0;
		}
	long long sum=0;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=S;i++)
		for(int j=i+1;j<=S;j++)
			sum+=1ll*vec[i].size()*vec[j].size()*614*n;
	for(int i=1;i<=S;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		for(int j=0;j<vec[i].size();j++)vis[vec[i][j]]=1;
		long long cnt=0;
		for(int j=0;j<vec[i].size();j++){
			int p=0;
			for(int k=0;k<vec[i].size();k++)
				if(j!=k&&con[vec[i][j]][vec[i][k]]){
					int v=vec[i][k];
					if(!p||con[p][v])p=v;
				}
			for(int k=0;k<vec[i].size();k++)
				if(j!=k){
					int v=vec[i][k];
					if(con[v][vec[i][j]]&&con[p][v])++cnt;
				}
		}
//		printf("%d %d %d\n",vec[i].size(),cnt,sum);
		sum+=cnt*2ll+(((1ll*vec[i].size()*(vec[i].size()-1))>>1ll)-cnt)*3ll;
	}
	printf("%lld\n",sum+((1ll*n*(n-1))>>1ll));
}