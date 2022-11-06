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
const int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
vector< pair < int , int > > edge[44];
bool exist[10001];
int Q,xt,yt,xe,ye,ans,now,f[1010][1010][44],b[1000100],c[1000100],t,w,x,y,xx,yy,n,m,K,i,j,a[1010][1010];
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();K=read();
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++)
	        a[i][j]=read(),edge[a[i][j]].push_back(make_pair(i,j));
    for (i=1;i<=n;i++)
       for (j=1;j<=m;j++)
           for (now=1;now<=K;now++)
              f[i][j][now]=1e9;
	for (now=1;now<=K;now++)
	     {
	     	t=1;w=0;
	     	for (i=1;i<=n;i++)
              for (j=1;j<=m;j++)
                  if (a[i][j]==now)
                      {
                      	w++;b[w]=i;c[w]=j;f[i][j][now]=0; 
					  }
			for (i=1;i<=K;i++) exist[i]=false;
			exist[now]=true;
		   while (t<=w)
		        {
		        	x=b[t];y=c[t];
					if (exist[a[x][y]]==false)
					for (i=0,exist[a[x][y]]=true;i<edge[a[x][y]].size();i++)
					    {
					    	xx=edge[a[x][y]][i].first;yy=edge[a[x][y]][i].second;
					    	if (f[xx][yy][now]>f[x][y][now]+1)
		        	     	      {
		        	     	      	f[xx][yy][now]=f[x][y][now]+1;w++;b[w]=xx;c[w]=yy;
								   }
						}
		        	for (i=0;i<4;i++)
		        	     {
		        	     	xx=x+d[i][0];yy=y+d[i][1];
		        	     	if ((xx>=1)&&(xx<=n)&&(yy>=1)&&(yy<=m)&&(f[xx][yy][now]>f[x][y][now]+1))
		        	     	      {
		        	     	      	f[xx][yy][now]=f[x][y][now]+1;w++;b[w]=xx;c[w]=yy;
								   }
							
						 }
		        	t++;
				}
		 }
	for (Q=read();Q;Q--)
	     {
	     	xt=read();yt=read();xe=read();ye=read();
	     	ans=abs(xt-xe)+abs(yt-ye);
	     	for (i=1;i<=K;i++) ans=min(ans,f[xt][yt][i]+f[xe][ye][i]+1);
	     	printf("%d\n",ans);
		 }
    return 0;
}