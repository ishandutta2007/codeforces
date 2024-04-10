#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
inline int read(){
	char c,p=0;int w;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');
	return p?-w:w;
}
const int N=2e5+5;
int n,m,k,q[N],dep[N],head[N],v[N<<1],nxt[N<<1],tot=1;
ll num[N];
inline void add(int x,int y){
	v[++tot]=y,nxt[tot]=head[x];head[x]=tot;
	v[++tot]=x,nxt[tot]=head[y];head[y]=tot;
}
void bfs(){
	int l,r,x;q[l=r=1]=1;dep[1]=1;
	while(l<=r)for(int i=head[x=q[l++]];i;i=nxt[i]){
		if(!dep[v[i]])dep[v[i]]=dep[x]+1,q[++r]=v[i]; 
	}
}
char s[N];
vector<string>ans;
int p[N];
inline bool cmp(int i,int j){return dep[i]<dep[j];}
inline void out(){printf("%d\n",ans.size());for(auto a:ans)cout<<a<<endl;}
void go(int u){
	if(u>n){
		ans.push_back(s+1);
		if(!--k)out(),exit(0);return;
	}
	int&x=p[u];
	for(int i=head[x];i;i=nxt[i])if(dep[v[i]]+1==dep[x])
	s[i>>1]='1',go(u+1),s[i>>1]='0';
}
int main(){
	n=read(),m=read(),k=read();
	REP(i,1,m)add(read(),read());
	bfs();
	REP(i,1,m)s[i]='0';s[m+1]='\0';
	REP(i,1,n)p[i]=i;sort(p+1,p+1+n,cmp);
	go(2);out();
	return 0;
}