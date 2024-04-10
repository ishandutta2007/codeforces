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
#define maxn 1<<19
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

int n,r,w;
double a[maxn],x,ans;

int main()
{
	n=read(); r=read(); w=(1<<n);
	for(int i=0;i<w;i++) scanf("%lf",&a[i]),ans+=a[i];
	printf("%.8lf\n",ans/w);
	for(int i=1;i<=r;i++)
	{
		int pos; scanf("%d%lf",&pos,&x);
		ans-=a[pos]; a[pos]=x; ans+=a[pos];
		printf("%.8lf\n",ans/w);
	}
	return 0;
}