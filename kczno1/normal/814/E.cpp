#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=52,D=1e9+7,W1=50,W2=50*50,W3=50*50*50,W4=50*50*50*50;
int n;
int d[N];ll c[N][N];
map<int,int>f[N];
bool open;
int dp(int x,int y1,int y2,int n1,int n2)
{
	if(y1<0||y2<0||n1<0||n2<0)return 0;
	if(x>n) return y1==0&&y2==0&&n1==0&&n2==0;
	
	int now=y1*W3+y2*W2+n1*W1+n2;
	if(f[x].count(now)) return f[x][now];
	
	ll ans=0;
	if(y1==0&&y2==0)
	{
		rep(x1,0,1)
		{
		   int x2=1-x1;
		   ans+=c[n1][x1]*c[n2][x2]%D*dp(x+1,n1-x1+x2,n2-x2,d[x]-x1-x2==1,d[x]-x1-x2==2);
		}
	}
	else
	{
		rep(x1,0,1)
		{
		 int x2=1-x1;
		if(y1-x1+x2>=0&&x2<=y2)
		{
		   int nd=d[x]-x1-x2;
		   rep(nx1,0,nd)
		   rep(nx2,0,nd-nx1)
		   {
		   	/*if(x==3&&x1==0&&x2==1&&nx1==1&&nx2==0)
		   	 int kcz=1;
		   	if(x==4&&x1==1&&x2==0&&nx1==1&&nx2==0&&y1==1&&n1==1)
		   	 open=1;*/
		    ans+=c[y1][x1]*c[y2][x2]%D*c[n1][nx1]%D*c[n2][nx2]%D*
			dp(x+1,y1-x1+x2,y2-x2,n1-nx1+nx2+(nd-nx1-nx2==1),
		                          n2-nx2+(nd-nx1-nx2==2));
		   }
		}
		}
    }
	return f[x][now]=ans%D;
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",d+i);
    rep(i,0,n)
    {
       c[i][0]=1;	
       rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%D;
	}
    printf("%d\n",dp(3,d[1]==2,d[1]==3,d[2]==2,d[2]==3));
}