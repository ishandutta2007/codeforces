#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=1e5+7;
int n,c[N];
vector<int> g[N];
ll ans[N],sum;
inline void add(int x,int y){g[x].push_back(y);}
int siz[N],cnt[N],in[N],out[N],dfn,rid[N],mx;
void getsz(int x,int f){
	siz[x]=1;in[x]=++dfn;rid[dfn]=x;
	for(int y:g[x])if(y!=f)getsz(y,x),siz[x]+=siz[y];
	out[x]=dfn;
}
void dfs(int x,int f,char kp){
	int hson=0;
	for(int y:g[x])if(y!=f&&siz[y]>siz[hson])hson=y;
	for(int y:g[x])if(y!=f&&y!=hson)dfs(y,x,0);
	if(hson)dfs(hson,x,1);
	for(int y:g[x])if(y!=f&&y!=hson)
		REP(i,in[y],out[y]){
			if(++cnt[c[rid[i]]]>mx)mx=cnt[c[rid[i]]],sum=0;
			if(cnt[c[rid[i]]]==mx)sum+=c[rid[i]];
		}
	if(++cnt[c[x]]>mx)mx=cnt[c[x]],sum=0;
	if(cnt[c[x]]==mx)sum+=c[x];
	ans[x]=sum;
	if(!kp){REP(i,in[x],out[x])--cnt[c[rid[i]]];sum=mx=0;}
}
int main(){
	n=read();
	REP(i,1,n)c[i]=read();
	REP(i,2,n){
		int x=read(),y=read();add(x,y),add(y,x);
	}
	getsz(1,-1);
	dfs(1,-1,0);
	REP(i,1,n)printf("%I64d ",ans[i]);
	return 0;
}