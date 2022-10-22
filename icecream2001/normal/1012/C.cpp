// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include <ctime>
#define LL long long
#define ept 1e-10
#define pa pair<int,int>
using namespace std;
const int N=1000050;
const LL mod=1e9+7;
const int inf=1e9;
int n,x,y,z;
int a[5050];
int f[5050][5050];
int main(){
	bool flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	a[0]=-inf;a[n+1]=-inf;
	for(int i=1;i<=(n+1)/2;++i){
		for(int j=0;j<=n;++j) f[j][i]=inf;
		x=inf;z=inf;
		if(i==1){
			for(int j=1;j<=n;++j){
				f[j][i]=(a[j-1]>=a[j]?a[j-1]-a[j]+1:0)+(a[j+1]>=a[j]?a[j+1]-a[j]+1:0);
				z=min(z,f[j][i]);
			}
			printf("%d",z);
			continue;
		}
		for(int j=0;j<=i*2-4;++j) x=min(x,f[j][i-1]);
		for(int j=i*2-1;j<=n;++j){
			f[j][i]=x+(a[j-1]>=a[j]?a[j-1]-a[j]+1:0)+(a[j+1]>=a[j]?a[j+1]-a[j]+1:0);
			y=min(a[j-1],a[j-2]-1);
			f[j][i]=min(f[j][i],f[j-2][i-1]+(y>=a[j]?y-a[j]+1:0)+(a[j+1]>=a[j]?a[j+1]-a[j]+1:0));
			z=min(z,f[j][i]);
			if(j-2>=0) x=min(x,f[j-2][i-1]);
		}
		printf(" ");
		printf("%d",z);
	}
	printf("\n");
	return 0;
}