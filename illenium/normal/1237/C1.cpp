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

struct node{int x,y,z,id;}p[maxn];
int n,pre[maxn],cnt,cnt2,f1,tmp,f2,cnt3;
vector <int> vec,vec2,vec3;
bool vis[maxn];

inline bool cmp(node x,node y)
{
	if(x.z!=y.z) return x.z<y.z;
	if(x.y!=y.y) return x.y<y.y;
	return x.x<y.x;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read(),p[i].z=read(),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	int l=1;
	for(int i=2;i<=n;i++)
	{
		if(l&&p[i].z==p[l].z&&p[i].y==p[l].y)
		{
			vis[l]=1; vis[i]=1;
			printf("%d %d\n",p[l].id,p[i].id); l=0;
		}
		else l=i;
	}
	l=1; while(vis[l]) l++;
	for(int i=l+1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(l&&p[l].z==p[i].z)
		{
			vis[i]=1; vis[l]=1;
			printf("%d %d\n",p[i].id,p[l].id); l=0;
		}
		else l=i;
	}
	l=1; while(vis[l]) l++;
	for(int i=l+1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(l)
		{
			vis[i]=1; vis[l]=1;
			printf("%d %d\n",p[l].id,p[i].id); l=0;
		}
		else l=i;
	}
	return 0;
}