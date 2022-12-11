#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1<<9;
int n,m,ans;
int a[maxn],b[maxn];
bool vis[maxn][maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void dfs(int p,int c){
	if(c>ans)return;
	if(p>n){
		ans=c;return;
	}
	if(vis[p][c])return;
	vis[p][c]=1;
	for(register int i=0;i<m;++i){
		dfs(p+1,c|(a[p]&b[i]));
	}
}
int main(){
	n=read();m=read();
	for(register int i=0;i<n;++i)a[i]=read();
	for(register int i=0;i<m;++i)b[i]=read();
	ans=maxn;
	dfs(0,0);
	printf("%d",ans);
	return 0;
}