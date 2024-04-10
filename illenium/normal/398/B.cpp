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
#define N 2005
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

int n,m,x,y,hang[N],lie[N];
double f[N][N];

int main()
{
	n=read(); m=read();
    for(int i=1;i<=m;++i)
    {
        x=read(); y=read();
        hang[x]=1,lie[y]=1;
    }
    x=0,y=0; for(int i=1;i<=n;++i) x+=hang[i],y+=lie[i];
    for(int i=n;i>=0;--i)
        for(int j=n;j>=0;--j)
        {
            if(i==n&&j==n) continue;
            double I=(double)i/(double)n,J=(double)j/(double)n;
            f[i][j]+=(f[i][j+1]+1.0)*I*(1.0-J);
            f[i][j]+=(f[i+1][j]+1.0)*(1.0-I)*J;
            f[i][j]+=(f[i+1][j+1]+1.0)*(1.0-I)*(1.0-J);
            f[i][j]+=I*J;
            f[i][j]/=(1.0-I*J);
        }
    printf("%.10lf\n",f[x][y]);
}