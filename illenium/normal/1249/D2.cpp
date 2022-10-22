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

struct node{int l,r,id;}p[maxn];
int f[maxn];
vector <int> ans;
priority_queue <node> q;

inline bool operator < (node a,node b)
{
	return a.r<b.r;
}

inline bool cmp(node x,node y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}

int main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;i++) p[i].l=read(),p[i].r=read()+1,p[i].id=i;
	sort(p+1,p+n+1,cmp);
	int cnt=1,nw=0;
	for(int i=1;i<=2e5;i++)
	{
		nw-=f[i];
		if(i==p[cnt].l)
		{
			while(p[cnt].l==i) q.push(p[cnt]),nw++,f[p[cnt].r]++,cnt++;
			while(nw>k)
			{
				node x=q.top(); q.pop(); nw--; f[x.r]--;
				ans.push_back(x.id);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}