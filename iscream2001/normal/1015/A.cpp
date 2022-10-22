#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define LL long long
using namespace std;
const int N=1e3;
int n,m,ans=0;
bool vis[N];
int main(){
	int u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
    	scanf("%d%d",&u,&v);
		for(int j=u;j<=v;++j)
			vis[j]=1; 
	}
	for(int i=1;i<=m;++i)
		if(!vis[i]){
			++ans;
		}
	printf("%d\n",ans);
	bool f=0;
	for(int i=1;i<=m;++i)
		if(!vis[i]){
			if(f)printf(" ");
			else f=1;
			printf("%d",i);
		}
	printf("\n");
	return 0;
}
/*
*/