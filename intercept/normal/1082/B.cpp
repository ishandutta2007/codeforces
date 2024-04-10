#include<iostream>
#include<cstdio>
using namespace std;
const int M=2e5+9;
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;char ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
char c[M];
int a[M],ans=0,sum=0;
int main(){
	int n=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;++i){
		if(c[i]=='G')a[i]=a[i-1]+1;
		if(c[i]=='S')a[i]=0;
		if(c[i]=='G')ans++;
	}
	for(int i=n-1;i>=1;--i){
		if(c[i]=='G'&&c[i+1]=='G')a[i]=a[i+1];
	}
	for(int i=1;i<=n;++i){
		if(c[i]=='S'&&ans-a[i-1]-a[i+1]>0)sum=max(sum,a[i-1]+a[i+1]+1);
		if(c[i]=='S'&&ans-a[i-1]-a[i+1]==0)sum=max(sum,a[i-1]+a[i+1]);
		else sum=max(sum,a[i]);
	}
	printf("%d\n",sum);
	return 0;
}
/*
5
GGSGG
*/