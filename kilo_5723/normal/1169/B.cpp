#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=3e5+5;
int a[maxn],b[maxn];
int n,m,x,y;
bool dfs(int p){
	if (p==m) return true;
	if (a[p]==x||a[p]==y||b[p]==x||b[p]==y)
		return dfs(p+1);
	if (x&&y) return false;
	if (!x){
		x=a[p];
		if (dfs(p+1)) return true;
		x=b[p];
		if (dfs(p+1)) return true;
		x=0;
		return false;
	}
	if (!y){
		y=a[p];
		if (dfs(p+1)) return true;
		y=b[p];
		if (dfs(p+1)) return true;
		y=0;
		return false;
	}
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++) scanf("%d%d",&a[i],&b[i]);
	puts(dfs(0)?"Yes":"No");
}