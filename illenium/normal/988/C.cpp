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

int a[maxn],sum;
struct node{int a,b,c;};
inline bool operator<(node a,node b){return a.a<b.a;}
map <int,node> mp;

int main()
{
	int k=read();
	for(int cas=1;cas<=k;cas++)
	{
		int n=read(); sum=0;
		for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
		for(int i=1;i<=n;i++)
		{
			if(mp[sum-a[i]].a==1)
			{
				puts("YES");
				printf("%d %d\n",mp[sum-a[i]].b,mp[sum-a[i]].c);
				printf("%d %d",cas,i);
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			mp[sum-a[i]]=(node){1,cas,i};
		}
	}
	puts("NO");
	return 0;
}