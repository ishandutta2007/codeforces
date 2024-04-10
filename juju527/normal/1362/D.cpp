#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=5e5+5;
struct Edge{
	int to,nxt;
}e[2*maxm];
int cnt;
int head[maxn];
int n,m;
int t[maxn];
int st[maxn];
int rd[maxn];
int ans[maxn];
bool vis[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
queue<int>q;
void topo(){
	for(int i=1;i<=n;i++)
		if(t[i]==1)q.push(i);
	int len=0;
	while(!q.empty()){
		int k=q.front();
		ans[++len]=k;
		q.pop();
		vis[k]=1;
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(t[k]<t[tmp])rd[tmp]--;
			if(rd[tmp]==0&&vis[tmp]==0)
				q.push(tmp);
		}
	}
	if(len<n){printf("-1\n");return ;}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]); 
	return ;
}
int main(){
	n=read();m=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();b=read();
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)t[i]=read();
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=head[i];j!=-1;j=e[j].nxt){
			int tmp=e[j].to;
			if(t[tmp]==t[i]){printf("-1\n");return 0;}
			if(st[t[tmp]]==0&&t[tmp]<t[i])cur++;
			if(t[tmp]<t[i])rd[i]++;
			st[t[tmp]]++;
		}
		if(cur<t[i]-1){printf("-1\n");return 0;}
		for(int j=head[i];j!=-1;j=e[j].nxt){
			int tmp=e[j].to;
			st[t[tmp]]--;
		}
	}
	topo();
	return 0;
}