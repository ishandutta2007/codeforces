#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=5020;
const int Zero=4000;
const int One=4010;

int d,mod;
int cell[maxn];
int X,Y;
int C[100][100];
int tot;

inline int power(int a,int b)
{
	int ans=1;
	while(b) (b&1?ans=(ll)ans*a%mod:0),b>>=1,a=(ll)a*a%mod;
	return ans;
}

inline void add(int a,int b,int c)
{
	printf("+ %d %d %d\n",a,b,c);
	cell[c]=(cell[a]+cell[b])%mod;
}

int tmp=3000;

inline void mul(int a,int c,int b)
{
	add(Zero,Zero,b); add(Zero,a,++tmp);
	while(c)(c&1?add(b,tmp,b),0:0),c>>=1,add(tmp,tmp,tmp);
}

int x[100];
int g[100][100];

inline int square(int a)
{
	if(d==2)return printf("^ %d %d\n",a,++tot),cell[tot]=power(cell[a],d),tot; 
	add(a,Zero,x[0]=++tot);
	REP(i,1,d)
	{
		add(tot,One,tot+1);x[i]=++tot;
	}
	REP(i,0,d)printf("^ %d %d\n",x[i],x[i]),cell[x[i]]=power(cell[x[i]],d);
	memset(g,0,sizeof(g));
	REP(i,0,d)REP(j,0,d)g[i][j]=(ll)power(i,d-j)*C[d][j]%mod;
	REP(i,0,d)g[i][d+1+i]=1;
	REP(i,0,d)
	{
		if(!g[i][i])
		{
			REP(j,i+1,d)if(g[j][i])
			{
				REP(l,i,2*d+1)swap(g[i][l],g[j][l]);
				break;
			}
		}
		
		REP(j,0,d)if(i!=j)
		{
			int tmp=(ll)g[j][i]*power(g[i][i],mod-2)%mod;
			REP(l,i,2*d+1)g[j][l]=(g[j][l]-(ll)tmp*g[i][l]%mod+mod)%mod;
		}
		REP(j,i+1,2*d+1)g[i][j]=(ll)g[i][j]*power(g[i][i],mod-2)%mod;
		g[i][i]=1;
	}
	int now=++tot; add(Zero,Zero,now);
	REP(i,0,d)mul(x[i],g[2][d+1+i],++tot),add(now,tot,now);
	return now;
}

inline void init()
{
	//srand(time(0)^(unsigned ll)new char);
	d=read(); mod=read();
	X=1,Y=2;
	REP(i,1,5000)cell[i]=1; cell[1]=X; cell[2]=Y;
	int t=mod-1; while(t)(t&1?add(Zero,Zero-1,Zero),0:0),t>>=1,add(Zero-1,Zero-1,Zero-1);
	C[0][0]=1;REP(i,1,d)REP(j,0,i)C[i][j]=((j?C[i-1][j-1]:0)+C[i-1][j])%mod;
	tot=2000;
}

inline void doing()
{
	add(1,2,3);
	int x2=square(1),y2=square(2),xy2=square(3);
	add(x2,y2,4); mul(4,mod-1,5);
	add(5,xy2,5);
	int inv2=(mod+1)>>1;
	mul(5,inv2,6);
	printf("f 6\n");
	//printf("%d * %d mod %d== %d\n",X,Y,mod,cell[6]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("decive.in","r",stdin);
	freopen("decive.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}