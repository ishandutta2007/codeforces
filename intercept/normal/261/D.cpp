#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const int M=2e7+9;
int n,t,m;
int dp[M],b[N],ma[M];
void add(int i,int v){
	for(;i<=m;i+=i&-i){
		if(ma[i]>=v)break;
		ma[i]=max(ma[i],v);
	}
}
int ask(int i,int rex=0){
	for(;i;i-=i&-i)rex=max(rex,ma[i]);
	return rex;
}
int read(){
	int rex=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')rex=rex*10+ch-'0',ch=getchar();
	return rex;
}
void work(){
	int ans=0;
	for(int i=1;i<=n;++i)b[i]=read();
	for(int j=1;j<=t;++j){
		for(int i=1;i<=n;++i){
			int y=ask(b[i]-1);
			if(y+1<=b[i])add(b[i],y+1);
			ans=max(ans,y+1);
			if(ans==m)break;
		}
	}
	for(int i=1;i<=m;++i)ma[i]=0;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d%d%d%d",&T,&n,&m,&t);
	t=min(t,m);
	while(T--)work();
	return 0;
}