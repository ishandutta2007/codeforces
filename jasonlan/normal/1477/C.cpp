#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=5010;
int n,x[maxn],y[maxn];
bool vis[maxn];
double pdis(int p,int q){
	return sqrt(1.0*(x[p]-x[q])*(x[p]-x[q])+1.0*(y[p]-y[q])*(y[p]-y[q]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	int p=1,q;
	double dis;
	for(int i=1;i<=n;++i){
		if(i>1)putchar(' ');
		printf("%d",p);
		vis[p]=true;
		q=-1;dis=0;
		for(register int j=1;j<=n;++j){
			if(vis[j])continue;
			if(pdis(p,j)>dis){
				dis=pdis(p,j);
				q=j;
			}
		}
		p=q;
	}	
	return 0;
}