#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
const int N=1e2+10;
int n,m;
LL a[N],b[N],mp[N][N],x=0,y=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
		x=x^a[i];
	}
	for(int i=1;i<=m;++i){
		scanf("%I64d",&b[i]);
		y=y^b[i];
	}
	if(x!=y) printf("NO\n");
	else{
		printf("YES\n");
		for(int i=1;i<n;++i){
			for(int j=1;j<m;++j) printf("0 ");
			printf("%I64d\n",a[i]);
		}
		y=a[n];
		for(int i=1;i<m;++i){
			printf("%I64d ",b[i]);
			y^=b[i];
		}
		printf("%I64d\n",y);
	}
	return 0;
}
/*
0 0 2
5 3 15
 */