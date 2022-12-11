#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=410000;
struct bian{
	int next,point;
}b[810000];
int n,p[N],len,size[N],f[N],g[N],where[N],u[N],lim,pd[N];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs(j,k1); size[k1]+=size[j];
			int k3=f[j];
			if (size[j]<=lim) k3=size[j];
			if (k3>f[k1]){
				g[k1]=f[k1]; f[k1]=k3; where[k1]=j;
			} else if (k3>g[k1]) g[k1]=k3;
		}
	}
}
void dfs2(int k1,int k2){
	int flag=0;
	if (n-size[k1]>lim){
		if (flag!=0) flag=-1;
		else {
			if (k1==where[k2]){
				u[k1]=max(u[k2],g[k2]);
			} else u[k1]=max(u[k2],f[k2]);
			if (n-size[k1]-u[k1]>lim) flag=-1;
			else flag++;
		}
	} else u[k1]=n-size[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs2(j,k1);
			if (size[j]>lim){
				if (flag!=0) flag=-1;
				else if (size[j]-f[j]>lim) flag=-1;
				else flag++;
			}
		}
	}
//	cout<<k1<<" "<<u[k1]<<endl;
	if (flag==-1) pd[k1]=0; else pd[k1]=1;
}
int main(){
	scanf("%d",&n); lim=n/2;
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	dfs(1,0); dfs2(1,0);
	for (int i=1;i<=n;i++) printf("%d ",pd[i]);
	return 0;
}