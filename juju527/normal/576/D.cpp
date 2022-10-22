//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=155,maxm=155;
int n,m;
struct edge{
	int u,v,w;
	bool operator <(edge i)const{return w<i.w;}
}ed[maxm];
struct Edge{int to,nxt;}e[maxm];
int cnt,head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
struct matrix{
	bitset<maxn> x[maxn];
	void unit(){
		for(int i=1;i<=n;i++)x[i].set(i);
		return ;
	}
	matrix operator *(matrix p)const{
		matrix res;
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
				if(x[i].test(k))
					res.x[i]|=p.x[k];
		return res;
	}
}T;
matrix power(matrix p,int b){
	matrix res;
	res.unit();
	while(b){
		if(b&1)res=res*p;
		p=p*p;
		b>>=1;
	}
	return res;
}
bitset<maxn> s,buf;
void trans(matrix p){
	buf.reset();
	for(int i=1;i<=n;i++)if(s.test(i))buf|=p.x[i];
	s=buf;
	return ;
}
int d[maxn];
queue<int> q;
void bfs(){
	while(q.size()){
		int k=q.front();
		q.pop();
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(d[tmp])continue;
			d[tmp]=d[k]+1;
			q.push(tmp);
		}
	}
	return ;
}
int main(){
	n=read();m=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int a,b,d;
		a=read();b=read();d=read();
		ed[i]=(edge){a,b,d};
	}
	sort(ed+1,ed+m+1);
	int t=0,res=1e9+n;
	s.set(1);
	for(int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		trans(power(T,w-t));t=w;
		add(u,v);T.x[u].set(v);
		for(int x=1;x<=n;x++)d[x]=0;
		for(int x=1;x<=n;x++)if(s.test(x))d[x]=1,q.push(x);
		bfs();
		if(d[n])res=min(res,t+d[n]-1);
	}
	if(res==1e9+n)puts("Impossible");
	else printf("%d\n",res);
    return 0;
}