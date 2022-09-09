#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=520;
const int maxk=17;
const int maxkbl=34;
const int BS=32;

struct tans
{
	uint a[maxk][maxk][2];
	
// 	inline void operator |=(pair<tans *,tans *> b)
// 	{
// 		for (int i=0;i<maxk;i++)
// 		{
// 			for (int j=0;j<maxk;j++) a[i][j]|=b.first->a[i][j],a[i][j]|=b.second->a[i][j];
// 		}
// 	}
	inline void operator =(int x)
	{
		memset(a,x,sizeof(a));
	}
};

struct tbl
{
	uint a[maxkbl];
	
	inline void operator |=(tbl b)
	{
		for (int j=0;j<maxkbl;j++) a[j]|=b.a[j];
	}
	inline void operator =(int x)
	{
		memset(a,x,sizeof(a));
	}
};

tans ans[maxk][maxk][2*BS];
tans curans[BS+3][BS+3];
tbl gofwd[maxk][maxk][BS+3][BS+3];
char p[maxn][maxn];
int n,m,kx,ky;
int KV=0;

inline bool ispoint(int x,int y)
{
	return (x==0 || y==0);
}

inline int whptbl(int x)
{
	return (x>>5);
}

inline int whptm(int x,int y)
{
	return 31-(x&31)+(y&31);
}

inline void dowith(tans * ans,int x,int y,int i,int j)
{
	if (i==0) ans->a[x][y][0]|=((uint)1<<j);
	else ans->a[x][y][1]|=((uint)1<<i);
}

inline void dowithbl(tbl * ans,int i,int j)
{
	if (i==BS && j==BS) return;
	if (j==BS) ans->a[BS+1]|=((uint)1<<i);
	else ans->a[i]|=((uint)1<<j);
}

inline bool getansbl(tbl * ans,int i,int j)
{
	if (j==BS) return (ans->a[BS+1] & ((uint)1<<i))>0;
	return (ans->a[i] & ((uint)1<<j))>0;
}

inline void calcbl(int x,int y)
{
	for (int i=0;i<BS;i++) curans[i][BS]=ans[x][y+1][whptm(i,0)];
	for (int i=0;i<BS;i++) curans[BS][i]=ans[x+1][y][whptm(0,i)];
	curans[BS][BS]=ans[x+1][y+1][whptm(0,0)];
	for (int i=BS-1;i>=0;i--)
	{
		for (int j=BS-1;j>=0;j--)
		{
			curans[i][j]=0;
			if (p[i+x*BS][j+y*BS]=='.')
			{
// 				curans[i][j]|=make_pair(&curans[i+1][j],&curans[i][j+1]);
				for (int ii=0;ii<maxk;ii++)
				{
					for (int jj=0;jj<maxk;jj++)
					{
						curans[i][j].a[ii][jj][0]|=curans[i+1][j].a[ii][jj][0];
						curans[i][j].a[ii][jj][0]|=curans[i][j+1].a[ii][jj][0];
						curans[i][j].a[ii][jj][1]|=curans[i+1][j].a[ii][jj][1];
						curans[i][j].a[ii][jj][1]|=curans[i][j+1].a[ii][jj][1];
						KV++;
					}
				}
				if (ispoint(i,j)) dowith(&curans[i][j],x,y,i,j);
			}
		}
	}
	memset(gofwd[x][y],0,sizeof(gofwd[x][y]));
	for (int i=BS;i>=0;i--)
	{
		for (int j=BS;j>=0;j--)
		{
			if (p[i+x*BS][j+y*BS]=='.')
			{
				gofwd[x][y][i][j]|=gofwd[x][y][i+1][j];
				gofwd[x][y][i][j]|=gofwd[x][y][i][j+1];
// 				KV++;
				dowithbl(&gofwd[x][y][i][j],i,j);
			}
			else gofwd[x][y][i][j]=0;
		}
	}
	for (int i=0;i<BS;i++)
	{
		ans[x][y][whptm(0,i)]=curans[0][i];
	}
	for (int i=0;i<BS;i++) 
	{
		ans[x][y][whptm(i,0)]=curans[i][0];
	}
}

inline void prepare()
{
	kx=((n+BS-1)>>5);
	ky=((m+BS-1)>>5);
	memset(ans,0,sizeof(ans));
	for (int i=kx-1;i>=0;i--)
	{
		for (int j=ky-1;j>=0;j--)
		{
			calcbl(i,j);
		}
	}
	return;
}

inline bool get(int x1,int y1,int x2,int y2)
{
	int xc1=(x1>>5);
	int yc1=(y1>>5);
	if (xc1==(x2>>5) && yc1==(y2>>5))
	{
		return getansbl(&gofwd[xc1][yc1][x1&31][y1&31],x2&31,y2&31);
	}
	int xm1=(x1&31);
	int ym1=(y1&31);
	int xc2=(x2>>5);
	int yc2=(y2>>5);
	int xm2=(x2&31);
	int ym2=(y2&31);
	uint curans0=0;
	uint curans1=0;
	for (int i=0;i<BS;i++) if (getansbl(&gofwd[xc1][yc1][xm1][ym1],i,BS))
	{
		curans1|=ans[xc1][yc1+1][whptm(i,0)].a[xc2][yc2][1];
		curans0|=ans[xc1][yc1+1][whptm(i,0)].a[xc2][yc2][0];
	}
	for (int i=0;i<BS;i++) if (getansbl(&gofwd[xc1][yc1][xm1][ym1],BS,i))
	{
		curans1|=ans[xc1+1][yc1][whptm(0,i)].a[xc2][yc2][1];
		curans0|=ans[xc1+1][yc1][whptm(0,i)].a[xc2][yc2][0];
	}
	bool answer=false;
	for (int i=0;i<BS;i++) if (curans1&((uint)1<<i)) answer|=getansbl(&gofwd[xc2][yc2][i][0],xm2,ym2);
	for (int i=0;i<BS;i++) if (curans0&((uint)1<<i)) answer|=getansbl(&gofwd[xc2][yc2][0][i],xm2,ym2);
	return answer;
}

int main()
{
	scanf("%d%d",&n,&m);
	char c;
	scanf("%c",&c);
	for (int i=0;i<n;i++)
	{
		while (c!='#' && c!='.') scanf("%c",&c);
		for (int j=0;j<m;j++) p[i][j]=c,scanf("%c",&c);
	}
	prepare();
	int nq;
	scanf("%d",&nq);
	for (int i=0;i<nq;i++)
	{
		int xa,xb,ya,yb;
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb),xa--,xb--,ya--,yb--;
		bool answer=get(xa,ya,xb,yb);
		printf("%s\n",answer ? "Yes" : "No");
	}
	cerr << KV << ' ' << (sizeof(ans)>>20) << " MB" << endl;
	return 0;
}