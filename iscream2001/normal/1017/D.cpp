#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=1e5+10;
int n,m,q;
int bin[20];
int a[5000];
int f[5000][200];
int w[20];
char s[20];
void dfs(int i,int j,int k,int s){
	if(k>100) return;
	if(j==n){
		f[i][k]+=a[s];
		return;
	}
	int x=(i&bin[j])/bin[j];
	dfs(i,j+1,k+w[j],s+x*bin[j]);
	dfs(i,j+1,k,s+(x^1)*bin[j]);
}
int main(){
	bin[0]=1;for(int i=1;i<=15;++i)bin[i]=bin[i-1]<<1;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;++i)
		scanf("%d",&w[i]);
	int x,y;
	for(int i=1;i<=m;++i){
		scanf("%s",s);x=0;
		for(int j=0;j<n;++j)
			x+=(s[j]-'0')*bin[j];
		++a[x];
	}
	//cout<<"y"<<endl;
	for(int i=0;i<bin[n];++i){
		dfs(i,0,0,0);
		for(int j=1;j<=100;++j)
			f[i][j]+=f[i][j-1];
	}
	int K;
	while(q--){
		scanf("%s",s);x=0;
		for(int j=0;j<n;++j)
			x+=(s[j]-'0')*bin[j];
		scanf("%d",&K);
		printf("%d\n",f[x][K]);
	}
	return 0;
} 
/*
2 4 5
40 20
01
01
10
11
00 20
00 40
11 20
11 40
11 60

*/