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
bool vis[1010][1010];
long long ans,ans3,ans4,x,y,tx,ty,ans1,ans2,sta,tot,f[1010][1010][3],n,m,i,j;
void Main(){
	x=read();y=read();
	tx=x-1;ty=y;sta=0;ans1=1;while ((tx>=1)&&(tx<=n)&&(ty>=1)&&(ty<=m)&&(vis[tx][ty]==false)){ans1++;if (sta==0) ty--;else tx--;sta^=1;}
	tx=x;ty=y+1;sta=0;ans2=1;while ((tx>=1)&&(tx<=n)&&(ty>=1)&&(ty<=m)&&(vis[tx][ty]==false)){ans2++;if (sta==0) tx++;else ty++;sta^=1;}
	tx=x+1;ty=y;sta=0;ans3=1;while ((tx>=1)&&(tx<=n)&&(ty>=1)&&(ty<=m)&&(vis[tx][ty]==false)){ans3++;if (sta==0) ty++;else tx++;sta^=1;}
	tx=x;ty=y-1;sta=0;ans4=1;while ((tx>=1)&&(tx<=n)&&(ty>=1)&&(ty<=m)&&(vis[tx][ty]==false)){ans4++;if (sta==0) tx--;else ty--;sta^=1;}
	tot=ans1*ans2+ans3*ans4-1;
	if (vis[x][y]==false) ans-=tot;
	else ans+=tot;
	vis[x][y]^=1;
	printf("%lld\n",ans);
	return ;
}
int main()
{
	n=read();m=read();int Testing=read();
	for (i=1;i<=n;i++)
	   for (j=1;j<=m;j++)
	       { 
	       f[i][j][0]=1;
	       f[i][j][1]=f[i][j-1][2]+f[i][j-1][0];
	       f[i][j][2]=f[i-1][j][1]+f[i-1][j][0];
	       ans+=f[i][j][0]+f[i][j][1]+f[i][j][2];
		   }
	for (;Testing;Testing--) Main();
    return 0;
}