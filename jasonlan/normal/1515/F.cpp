#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=301000;
int n,m;
ll c,a[maxn],sum;
bool vis[maxn];
vector <int> v[maxn],vno[maxn];
stack <int> S;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void dfs(int p){
	vis[p]=true;
	for(int i=0,to;i<v[p].size();++i){
		to=v[p][i];
		if(vis[to])continue;
		dfs(to);
		if(a[p]+a[to]<c)S.push(vno[p][i]);
		else{
			printf("%d\n",vno[p][i]);
			a[p]+=a[to]-c;
		}
	}
}
int main(){
	n=read();m=read();c=read();
	for(int i=1;i<=n;++i)
		sum+=(a[i]=read());
	if(sum<c*(n-1)){
		puts("NO");return 0;
	}
	puts("YES");
	for(int i=1,x,y;i<=m;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
		vno[x].push_back(i);
		vno[y].push_back(i);
	}
	dfs(1);
	while(S.size())printf("%d\n",S.top()),S.pop();
	return 0;
}