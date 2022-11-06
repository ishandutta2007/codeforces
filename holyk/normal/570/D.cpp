#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=5e5+7;
int n,m,siz[N],dep[N];
vector<int> g[N];
struct ask{int h,id;};
vector<ask> q[N];
void getsz(int x){
	siz[x]=1;
	for(auto i:g[x])dep[i]=dep[x]+1,getsz(i),siz[x]+=siz[i];
}
char c[N],ans[N];
int cnt[26][N],hson;
void calc(int x,int w){
	cnt[c[x]-'a'][dep[x]]+=w;
	for(auto y:g[x])if(y!=hson)calc(y,w);
}
void dfs(int x,char kp){
	int son=0;
	for(auto y:g[x])if(siz[y]>siz[son])son=y;
	for(auto y:g[x])if(y!=son)dfs(y,0);
	if(son)dfs(son,1),hson=son;
	calc(x,1);hson=0;
	for(auto y:q[x]){
		int t=0;
		REP(i,0,25)if(cnt[i][y.h]&1)++t;
		ans[y.id]=t<=1;
	}
	if(!kp)calc(x,-1);
}
int main(){
	n=read(),m=read();
	REP(i,2,n)g[read()].push_back(i);
	scanf("%s",c+1);
	REP(i,1,m){
		int x=read(),d=read();
		q[x].push_back({d,i});
	}
	dep[1]=1;getsz(1);dfs(1,0);
	REP(i,1,m)puts(ans[i]?"Yes":"No");
	return 0;
}