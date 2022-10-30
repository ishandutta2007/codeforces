// Hydro submission #61f4b9ef8c1511038a90e930@1643428336271
#include<bits/stdc++.h>
using namespace std;
inline void read(long long &x)
{
x=0;int f=1;char s=getchar();
for(;s<'0'||s>'9';s=getchar()) if(s=='-') f=-1;
for(;s>='0'&&s<='9';s=getchar()) x=(x<<3)+(x<<1)+s-48;
x*=f;
}
inline void write(long long x)
{
if(x<0){
putchar('-');
x=-x;
}
if(x>9)write(x/10);
putchar(x%10+'0');
}
struct hzy {
	long long val,next,v;
} e[400001];
long long t,linkk[200001],zishu[200001],n,max1=0,sum;
long long dis[200001],Dp[200001];
void ling(long long x,long long y,long long z) {
	e[++t].val=y;
	e[t].v=z;
	e[t].next=linkk[x];
	linkk[x]=t;
}
void dfs(long long x,long long father)
{
	for(long long i=linkk[x];i;i=e[i].next){
		long long y=e[i].val;
		if(y==father) continue;
		dfs(y,x);
		dis[y]=dis[x]+e[i].v*zishu[y];
		zishu[x]+=zishu[y];
	}
}
void treedp(long long x,long long father){
    for (long long i=linkk[x];i;i=e[i].next){
	    long long y=e[i].val;
	    if (y==father) continue;
	    Dp[y]=Dp[x]+(sum-zishu[y])*e[i].v-(zishu[y])*e[i].v;
	    treedp(y,x);
	}
}
int main()
{
	read(n);
	for(long long i=1;i<=n;i++){
		cin>>zishu[i];
		sum+=zishu[i];
	}
	for(long long i=1,x,y,z;i<n;i++){
		read(x);
		read(y);
		ling(x,y,1);
		ling(y,x,1);
	}
	dfs(1,0);
	for(long long i=1;i<=n;i++){
		Dp[1]+=dis[i];
	}
	treedp(1,0);
	for(long long i=1;i<=n;i++){
		max1=max(max1,Dp[i]);
	}
	cout<<max1;
	return 0;
}