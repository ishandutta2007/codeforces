#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int N=1001,M=10000001;
int son[M][2],fail[M],q[M],h,t,n,nl,points,id[M],S,T;
int head[N<<1],nxt[4000001],b[4000001],k,res[N<<1];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool vis[N<<1];
bool con[N][N];
std::vector<int>vec[N];
char str[M];
void get_fail(){
	for(int i=0;i<2;i++)
		if(son[0][i])q[++t]=son[0][i];
	while(h<t){
		++h;
		id[q[h]]=(id[q[h]]?id[q[h]]:id[fail[q[h]]]);
		for(int i=0;i<2;i++)
			if(son[q[h]][i])fail[son[q[h]][i]]=son[fail[q[h]]][i],q[++t]=son[q[h]][i];
			else son[q[h]][i]=son[fail[q[h]]][i];
	}
}
bool match(int x){
	for(int i=head[x];i;i=nxt[i])
		if(!vis[b[i]]){
			vis[b[i]]=1;
			if(!res[b[i]]||match(res[b[i]])){
				res[b[i]]=x,res[x]=b[i];
				return 1;
			}
		}
	return 0;
}
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(res[b[i]]&&!vis[b[i]]){
			vis[b[i]]=1;
			dfs(res[b[i]]);
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1,j,now;i<=n;i++){
		scanf("%s",str+1);
		for(j=1,now=0;str[j];j++){
			if(!son[now][str[j]-'a'])son[now][str[j]-'a']=++points;
			now=son[now][str[j]-'a'];
			vec[i].push_back(now);
			str[j]=0;
		}
		id[now]=i;
	}
	get_fail();
	for(int i=1;i<=n;i++){
		for(int j=0;j<vec[i].size()-1;j++)
			con[i][id[vec[i][j]]]=1;
		con[i][id[fail[vec[i].back()]]]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				con[i][j]|=(con[i][k]&con[k][j]);
	T=(n<<1)+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(con[i][j])
				push(i,j+n);
	int tem=n;
	for(int i=1;i<=n;i++)
		if(!res[i]){
			for(int j=1;j<=n<<1;j++)vis[j]=0;
			if(match(i))tem--;
		}
	printf("%d\n",tem);
	for(int i=1;i<=n<<1;i++)vis[i]=0;
	for(int i=1;i<=n;i++)if(!res[i])dfs(i);
	for(int i=1;i<=n;i++)if(vis[i]&&!vis[i+n])printf("%d ",i);
}