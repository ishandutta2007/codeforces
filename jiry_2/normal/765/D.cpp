#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n,x[110000],m,pd[110000],size[110000],g[110000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		size[x[i]]++;
		if (i==x[i]) pd[x[i]]=1;
	}
	for (int i=1;i<=n;i++)
		if (pd[i]==0&&size[i]){
			printf("-1\n"); return 0;
		}
	m=0;
	for (int i=1;i<=n;i++) if (size[i]) m++,pd[i]=m,g[m]=i;
	printf("%d\n",m);
	for (int i=1;i<=n;i++)
		printf("%d ",pd[x[i]]);
	printf("\n");
	for (int i=1;i<=m;i++)
		printf("%d ",g[i]);
	printf("\n");
	return 0;
}