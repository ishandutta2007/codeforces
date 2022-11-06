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
int n,m;
vector<int> g[N],s;
int dep[N],d[N];
void dfs1(int x,int f){
	for(int y:g[x])if(y!=f)dep[y]=dep[x]+1,dfs1(y,x);
}
void dfs2(int x,int f){
	d[x]=1;int son=0;
	for(int y:g[x])if(y!=f){
		dfs2(y,x);
		if(d[x]<d[y]+1)d[x]=d[y]+1,son=y;
	}
		
	for(int y:g[x])if(y!=f&&y!=son)s.push_back(d[y]);
}
int main(){
	n=read();
	REP(i,2,n){
		int x=read(),y=read();
		g[x].push_back(y);g[y].push_back(x);
	}
	dep[1]=1,dfs1(1,0);
	int rt=0;
	REP(i,1,n)if(dep[i]>dep[rt])rt=i;
	dfs2(rt,0);s.push_back(d[rt]);
	sort(s.begin(),s.end(),greater<int>());	
	printf("1 ");
	int ans=0;
	int j=0;
	REP(i,2,n){
		if(j<s.size())ans+=s[j++];
		printf("%d ",ans);
	}
	return 0;
}