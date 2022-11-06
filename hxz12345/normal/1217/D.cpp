#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long pow(long long x,long long y,long long p)
{
    long long ans=1;
    for (;y;y>>=1,x=x*x % p)
        if (y&1) ans=ans*x % p;
    return ans;
}
vector<int> edge[5010],edge1[5010];
bool e[5010][2][5010];
int hh1[5010][5010],hh2[5010][5010];
int a[101000],b[101000],id[101000];
bool exist[101000];
int n,m,i,x,y,j,tot;
void dfs(int x,int fa,int sta,int now)
{
	if (e[x][sta][now]) return ;
	e[x][sta][now]=true;
	if (sta==1)
	    {
	for (int i=0;i<edge[x].size();i++)
	     {
	     	int y=edge[x][i];
	     	if (hh1[x][y]!=now) continue;
	     	if (y!=fa)
	     	    dfs(y,x,sta,now);
		 }
	   }
	else
	    {
	    	for (int i=0;i<edge1[x].size();i++)
	     {
	     	int y=edge1[x][i];
	     	if (hh2[x][y]!=now) continue;
	     	if (y!=fa)
	     	    dfs(y,x,sta,now);
		 }
		}
}
int main()
{
	n=read();m=read();
	for (i=1;i<=m;i++)
	     {
	     	x=read();y=read();
			for (j=1;j<m;j++)
			    e[a[j]][0][id[j]]=e[a[j]][1][id[j]]=e[b[j]][1][id[j]]=e[b[j]][0][id[j]]=false;
	     	for (j=1;j<=tot;j++) exist[j]=false;
	     	for (j=1;j<=tot;j++)
	     	    {
	     	    	dfs(x,0,1,j);dfs(y,0,0,j);
				 }
			for (j=1;j<m;j++)
			    if (e[a[j]][0][id[j]]&&e[a[j]][1][id[j]]&&e[b[j]][1][id[j]]&&e[b[j]][0][id[j]])
			         exist[id[j]]=true;
			for (j=1;j<=tot;j++)
			    if (exist[j]==false) break;
	        id[i]=j;
	        if (j>tot) tot++;
	        hh1[y][x]=id[i];hh2[x][y]=id[i];
	     	edge[y].push_back(x);edge1[x].push_back(y);
	     	a[i]=x;b[i]=y;
	    }
	printf("%d\n",tot);
	for (i=1;i<=m;i++) printf("%d ",id[i]);
    return 0;
}