#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,p,k,x,y;
int f[M];
char c[M];
void work(){
	int mi=1e9;
	scanf("%d%d%d%s%d%d",&n,&p,&k,c+1,&x,&y);
	for(int i=1;i<=2*n;++i)f[i]=1e9;
	for(int i=p;i<=n;++i)f[i]=(i-p)*y;
	for(int i=p;i<=n;++i){
		f[i+k]=min(f[i+k],f[i]+(c[i]=='0')*x);
		if(i+1>n)mi=min(mi,f[i+1]);
		if(i+k>n)mi=min(mi,f[i+k]);
	}
	printf("%d\n",mi);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
11 2 3
10110011000
4 3

*/