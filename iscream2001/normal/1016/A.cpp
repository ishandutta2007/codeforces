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
const int N=2e5+10;
int n,m,x;
int a[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	x=m;
	int ans;
	for(int i=1;i<=n;++i){
		ans=0;
		if(a[i]<x){
			x-=a[i];
			printf("0 ");
			continue;
		}
		a[i]-=x;ans=1;
		x=m;
		ans+=a[i]/m;
		a[i]%=m;
		x-=a[i];
		printf("%d ",ans);
	}
	return 0;
}