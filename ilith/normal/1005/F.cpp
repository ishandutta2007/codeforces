#include<bits/stdc++.h>
#define rgi register int
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;
	char ch=getchar();
	while(!(ch&16)){if(ch=='-')f=-1;ch=getchar();}
	while(ch&16)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
int n,m,u,v;
long long k,res=1;
struct node{
	int id,d;
};
bool operator<(node a,node b){
	return a.d>b.d;
}
int e[200010];
vector<int>a[200010],ch[200010];
int d[200010],vis[200010];
priority_queue<node>q;
void dfs(rgi x){
	if(x>n){
		for(rgi i=1;i<=m;++i)putchar((e[i]<0)+'0');
		return puts(""),--k,void();
	}
	for(rgi i=0;i<ch[x].size();++i){
		if(!k)return;
		int to=ch[x][i];
		e[to]=~e[to],dfs(x+1),e[to]=~e[to];
	}
}
int main(){
	read(n,m,k);
	for(rgi i=1;i<=m;++i){
		read(u,v),e[i]=u^v;
		a[u].push_back(i),a[v].push_back(i);
	}
	memset(d,127,sizeof d);
	d[1]=0,q.push(node{1,0});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(rgi i=0;i<a[x].size();i++){
			int to=e[a[x][i]]^x;
			if(d[to]>d[x]+1){
				d[to]=d[x]+1;
				if(!vis[to])q.push(node{to,d[to]});
			}
		}
	}
	for(rgi i=1;i<=n;++i){
		for(rgi j=0;j<a[i].size();++j){
			int to=e[a[i][j]]^i;
			if(d[to]==d[i]+1)ch[to].push_back(a[i][j]);
		}
	}
	for(rgi i=2;i<=n;++i){
		res*=(long long)ch[i].size();
		if(res>k)break;
	}
	k=min(res,k),cout<<k<<'\n';
	dfs(2);
	return 0;
}