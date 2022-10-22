#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,L,W,A[maxn],B[maxn],t1,t2;
ll ans; 

int main()
{
	n=read(); L=read(); W=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(y==1) A[++t1]=x;
		else B[++t2]=x;
	}
	sort(A+1,A+t1+1); sort(B+1,B+t2+1);
	for(int i=1,j=1;i<=t1;i++)
	{
		while(j<=t2&&abs(A[i]+B[j]+L)>=1ll*W*(B[j]-A[i]+L)) j++;
		ans+=t2-j+1;
	}
	cout<<ans<<endl;
	return 0;
}