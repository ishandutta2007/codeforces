#include<iostream>
#include<cstdio>
using namespace std;
const int M=5e5+9;
int n,k,num=0,m=0,sum=0;
int head[M],b[M];
struct P{int to,ne;}e[M];
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
int main(){
	n=read(),k=read();
	for(int i=n;i>=1;--i){
		int x=read();m=max(m,x);
		e[++num]=(P){i,head[x]};head[x]=num;
	}
	for(int i=head[k];i;i=e[i].ne){
		b[e[i].to]++;
	}
	for(int i=1;i<=n;++i)b[i]+=b[i-1];
	sum=b[n];
	for(int u=1;u<=m;++u){
		if(u==k||!head[u])continue;
		int ans=b[n]+1;sum=max(sum,ans);
		for(int la=head[u],i=e[la].ne;i;la=i,i=e[i].ne){
			int cnt=b[e[i].to]-b[e[la].to];
			if(ans-cnt<=b[n])ans=b[n]+1;
			else ans=ans-cnt+1;
			sum=max(sum,ans);
		}
	}
	printf("%d",sum);
	return 0;
}