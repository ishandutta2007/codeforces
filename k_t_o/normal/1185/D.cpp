#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 260004
int b[N],a[N],n,d,j;
int main()
{
	//read   shunxu wenti ///
	n=read();for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)b[i]=a[i];//memcpy  memset //...
	sort(b+1,b+n+1);
	d=b[2]-b[1];
	for(int i=3;i<=n;++i){
		if(j==i-1){
			if(b[i]-b[i-2]==d)continue;
			j=-1; continue;
		}
		if(b[i]-b[i-1]==d)continue;
		if(j)j=-1;else j=i;
	}
	if(!j)j=1;
	if(j!=-1){
		j=b[j];
		for(int i=1;i<=n;++i)if(a[i]==j){
			printf("%d",i);exit(0);//goto  ///lll ///
		}
	}
	if(n>=3){
		d=b[3]-b[2]; j=1;
		for(int i=4;i<=n;++i){
			if(b[i]-b[i-1]==d)continue;
			j=-1; break;
		}
		if(j==1){
			for(int i=1;i<=n;++i)if(a[i]==b[1]){
				printf("%d",i);exit(0);
			}
		}
		d=b[3]-b[1];j=2;
		for(int i=4;i<=n;++i){
			if(b[i]-b[i-1]==d)continue;
			j=-1; break;
		}
		if(j==2){
			for(int i=1;i<=n;++i)if(a[i]==b[2]){
				printf("%d",i);exit(0);
			}
		}
	}
	puts("-1");
}