#include <cstdio>
#include <vector>
#include <cstring>

const int N=1000010;
int n;
char str[N];
int son[N][26],pre[N];
int cnt;
int q[N],h,t,fa[N];
std::vector<int>vec[N];
int tot[N];
int c[N];
void update(int ind,int num){for(;ind<=cnt+1;ind+=ind&-ind)c[ind]+=num;}
int query(int ind){int tot=0;for(;ind;ind-=ind&-ind)tot+=c[ind];return tot;}
int dfn[N],mx[N],now;
int nxt[N],head[N],b[N],k;
bool res[N];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x){
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]);
	mx[x]=now;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		int nl=strlen(str+1);
		for(int j=1,now=0;j<=nl;++j){
			int &p=son[now][str[j]-'a'];
			if(!p)p=++cnt;
			now=p;
			vec[i].push_back(now);
		}
		pre[vec[i].back()]=i;
	}
	for(int i=0;i<26;++i)
		if(son[0][i])q[++t]=son[0][i];
	while(h<t){
		++h;
		pre[q[h]]=pre[q[h]]?pre[q[h]]:pre[fa[q[h]]];
		push(fa[q[h]],q[h]);
		for(int i=0;i<26;++i)
			if(son[q[h]][i])q[++t]=son[q[h]][i],fa[son[q[h]][i]]=son[fa[q[h]]][i];
			else son[q[h]][i]=son[fa[q[h]]][i];
	}
	dfs(0);
	int ans=0;
	for(int i=1;i<=n;++i){
		std::vector<int>tem;
		for(int j=0;j<vec[i].size();++j){
			int u=pre[vec[i][j]];
			if(j+1==(int)vec[i].size())u=pre[fa[vec[i][j]]];
			update(dfn[vec[i][j]],1);
			if(!u)continue;
			if(!tot[u])tem.push_back(u);
			++tot[u];
			res[u]=1;
		}
		for(int i=0;i<tem.size();++i){
			int u=tem[i];
			if(query(mx[vec[u].back()])-query(dfn[vec[u].back()]-1)!=tot[u])res[u]=0;
		}
		for(int j=vec[i].size()-1,len=0x7f7f7f7f;~j;--j){
			int u=pre[vec[i][j]];
			if(j+1==(int)vec[i].size())u=pre[fa[vec[i][j]]];
			update(dfn[vec[i][j]],-1);
			if(!u)continue;
			if(len<=j+1-vec[u].size()+1)res[u]=0;
			len=std::min(len,j+1-(int)vec[u].size()+1);
		}
		for(int i=0;i<tem.size();++i){
			int u=tem[i];
			tot[u]=0;
			if(res[u])++ans;
		}
	}
	printf("%d\n",ans);
}