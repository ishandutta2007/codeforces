#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[210000];
vector<int>A,B;
int p[110000],len,n,m,pd[110000],flag;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	if (pd[k1]!=-1){
		if (pd[k1]!=k2) flag=1; return;
	}
	pd[k1]=k2;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		dfs(j,k2^1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	memset(pd,0xff,sizeof pd);
	for (int i=1;i<=n;i++){
		if (pd[i]==-1) dfs(i,0);
		if (pd[i]==0) A.push_back(i); else B.push_back(i);
	}
	if (flag){
		printf("-1\n");
	} else {
		printf("%d\n",(int)A.size());
		for (int i=0;i<A.size();i++) printf("%d ",A[i]); printf("\n");
		printf("%d\n",(int)B.size());
		for (int i=0;i<B.size();i++) printf("%d ",B[i]); printf("\n");
	} 
	return 0;
}