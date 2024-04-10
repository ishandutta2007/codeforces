#include<cstdio>
#include<stack>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5005;
int n, m,tot,head[N<<1],nex[N<<2],to[N<<2];
struct node
{
	int p, c;
}a[N];
int f[N<<1];
bool vis[N],vv[N<<1];
stack<int>s,ans;
void add(int u, int v)
{
    to[++tot]=v;nex[tot]=head[u];head[u]=tot;
}
bool match(int x)
{
    vv[x]=true;
    for(int i=head[x];i;i=nex[i])
    {
        int v=to[i];
        if(f[v]==-1||!vv[f[v]]&&match(f[v]))
        {
            f[v]=x;
            return true;
        }
    }
    return false;
}
int main()
{
    memset(f,-1,sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i].p);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i].c);
	int d;
	scanf("%d", &d);
	while (d--)
	{
		int x;
		scanf("%d", &x);
		s.push(x);
		vis[x] = true;
	}
	for (int i = 1;i <= n;i++)
		if (!vis[i]) add(a[i].p, N+a[i].c);
    int now=0;
	while (!s.empty())
	{
	    while(match(now))
        {

            now++;
            memset(vv,false,sizeof(vv));
        }
        memset(vv,false,sizeof(vv));
        add(a[s.top()].p,N+a[s.top()].c);
        s.pop();
        ans.push(now);
	}
	while (!ans.empty())
	{
		int now = ans.top();ans.pop();
		printf("%d\n",now);
	}
}