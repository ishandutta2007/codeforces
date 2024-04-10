#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int size[310000],p[310000],father[310000],ans[310000];
struct bian{
	int next,point;
}b[610000];
int n,m,len;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void treedp(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp(j,k1); size[k1]+=size[j];
		}
	}
	int where=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&size[j]*2>size[k1]) where=j;
	}
	if (where==0){
		ans[k1]=k1; return;
	}
	ans[k1]=ans[where];
	while ((size[k1]-size[ans[k1]])*2>size[k1])
		ans[k1]=father[ans[k1]];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int k1; scanf("%d",&k1); father[i+1]=k1; add(k1,i+1);
	}
	treedp(1,0);
	for (;m;m--){
		int k1; scanf("%d",&k1); printf("%d\n",ans[k1]);
	}
	return 0;
}