#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=205,mxd=1000100;
int n,m,s,t,ans;
char ch[maxn][maxn];
int head[mxd],nxt[mxd],rdc[mxd],flow[mxd],tnt=1;
int no[mxd];
bool vis[mxd];
queue<int>q;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v,int f){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	flow[tnt]=f;
}
bool bfs(){
	for(register int i=s;i<=t;++i)
		no[i]=0;
	no[s]=1;
	q.push(s);
	while(q.size()){
		int p=q.front();
		q.pop();
		for(register int i=head[p];i;i=nxt[i])
			if(flow[i]&&!no[rdc[i]]){
				no[rdc[i]]=no[p]+1;
				q.push(rdc[i]);
			}
	}
	return no[t];
}
int dinic(int p,int f){
	if(p==t)return f;
	int fl=0;
	for(register int i=head[p];i&&f;i=nxt[i])
		if(flow[i]&&no[rdc[i]]==no[p]+1){
			int t=dinic(rdc[i],min(f,flow[i]));
			f-=t;fl+=t;flow[i]-=t;flow[i^1]+=t;
		}
	if(!fl)no[p]=-1;
	return fl;
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		scanf("%s",ch[i]+1);
	s=0;t=2*n*m+1;
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			if(ch[i][j]=='#'){
				++ans;
				int up=(i-1)*m+j+n*m,down=i*m+j+n*m;
				int left=i*m+j-1,right=i*m+j;
				if(ch[i][j+1]=='#'&&!vis[right]){
					--ans;
					add(s,right,1),add(right,s,0);
				}
				if(ch[i+1][j]=='#'&&!vis[down]){
					--ans;
					add(down,t,1),add(t,down,0);
				}
				if(ch[i-1][j]=='#'){
					if(ch[i][j-1]=='#')add(left,up,1),add(up,left,0);
					if(ch[i][j+1]=='#')add(right,up,1),add(up,right,0);
				}
				if(ch[i+1][j]=='#'){
					if(ch[i][j-1]=='#')add(left,down,1),add(down,left,0);
					if(ch[i][j+1]=='#')add(right,down,1),add(down,right,0);
				}
			}
	while(bfs())ans+=dinic(s,1<<29);
	printf("%d\n",ans);
	return 0;
}