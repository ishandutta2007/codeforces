#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=18;
int n;
double mat[maxn][maxn],f[1<<maxn];
int main(){
	scanf("%d",&n);
	for(register int i=0;i<n;++i)
		for(register int j=0;j<n;++j)
			scanf("%lf",&mat[i][j]);
	f[(1<<n)-1]=1;
	for(register int i=(1<<n)-1,s;i;--i){
		s=0;
		for(register int j=0;j<n;++j)
			s+=((i>>j)&1);
		if(s==1)continue;
		for(register int j=0;j<n;++j){
			if(!((i>>j)&1))continue;
			for(register int k=0;k<n;++k){
				if(!((i>>k)&1))continue;
				f[i^(1<<j)]+=f[i]*mat[k][j]*2/s/(s-1);
			}
		}
	}
	for(register int i=0;i<n;++i)
		printf("%.6lf ",f[1<<i]);
	return 0;
}