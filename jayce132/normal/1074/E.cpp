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
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=22;

int n,m,g[maxn][maxn],X[maxn*maxn],Y[maxn*maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)REP(j,1,m)g[i][j]=read(),X[g[i][j]]=i,Y[g[i][j]]=j;
}

struct point {
	int x,y;
	point(int a=0,int b=0){ x=a; y=b;}
};

inline point operator + (point a,point b){ return point(a.x+b.x,a.y+b.y);}
inline point operator - (point a,point b){ return point(a.x-b.x,a.y-b.y);}

#define P(v) g[(v).x][(v).y]

const point tr[4]={point(0,1),point(1,0),point(0,-1),point(-1,0)};

inline point GetPoint(int x)
{
	return point((x-1)/m+1,(x-1)%m+1);
}

inline int GetVal(point x)
{
	return (x.x-1)*m+x.y;
}

inline void Swap(point a,point b)
{
	int &v1=g[a.x][a.y],&v2=g[b.x][b.y];
	swap(X[v1],X[v2]); swap(Y[v1],Y[v2]);
	swap(v1,v2);
	//swap(a,b);
}

int tot;
vector<int>Ans[100020];

inline void Move4(point &a,int turn1,int turn2)//
{
	point b=a+tr[turn1],c,d;
	c=b+tr[turn2]; d=a+tr[turn2];
	vector<int>v;
	v={P(a),P(b),P(c),P(d)};
	Ans[++tot]=v;//Ans.push_back(v);
    //printf("4 %d %d %d %d\n",P(a),P(b),P(c),P(d)); 
	
	Swap(c,d); Swap(b,c); Swap(a,b);	
	a=b;
	
	/*printf("Case:%d\n",(int)Ans.size());
	REP(i,1,n)
	{
		REP(j,1,m)printf("%d ",g[i][j]);
		puts("");
		}*/
	//puts("");
}

inline void Move4_(point a,int turn1,int turn2)//
{
	point b=a+tr[turn1],c,d;
	c=b+tr[turn2]; d=a+tr[turn2];
	vector<int>v;
	v={P(a),P(b),P(c),P(d)};
	//printf("4 %d %d %d %d\n",P(a),P(b),P(c),P(d));
	//puts("");
	Ans[++tot]=v;//Ans.push_back(v);
	Swap(c,d); Swap(b,c); Swap(a,b);	
	//Swap(a,b); Swap(b,c); Swap(c,d);
	//a=b;
	/*printf("Case:%d\n",(int)Ans.size());
	REP(i,1,n)
	{
		REP(j,1,m)printf("%d ",g[i][j]);
		puts("");
	}

	puts("");*/
	
}

#define Right 0
#define Left 2
#define Up 3
#define Down 1

inline void MOVEUP()
{
	vector<int>v;
	v={g[1][1],g[1][2],g[1][3],g[2][3],g[2][2],g[2][1]};
	//printf("6 %d %d %d %d %d %d\n",g[1][1],g[1][2],g[1][3],g[2][3],g[2][2],g[2][1]);
	Swap(point(2,2),point(2,1)); Swap(point(2,3),point(2,2));
	Swap(point(1,3),point(2,3)); Swap(point(1,2),point(1,3)); 
	Swap(point(1,1),point(1,2));
	Ans[++tot]=v;//Ans.push_back(v);
		
	/*printf("Case:%d\n",(int)Ans.size());
	  REP(i,1,n)
	  {
	  REP(j,1,m)printf("%d ",g[i][j]);
	  puts("");
	  }

	  puts("");*/
		
	Move4_(point(1,2),Down,Right);
	Move4_(point(1,2),Left,Down);
}

inline void MOVEDOWN()
{
	vector<int>v;
	v={g[1][1],g[2][1],g[2][2],g[2][3],g[1][3],g[1][2]};
	//printf("6 %d %d %d %d %d %d\n",g[1][1],g[2][1],g[2][2],g[2][3],g[1][3],g[1][2]);
	Ans[++tot]=v;//Ans.push_back(v);

		
		
	Swap(point(1,1),point(1,2)); Swap(point(1,2),point(1,3));
	Swap(point(1,3),point(2,3)); Swap(point(2,3),point(2,2));
	Swap(point(2,2),point(2,1));

	/*printf("Case:%d\n",(int)Ans.size());
	  REP(i,1,n)
	  {
	  REP(j,1,m)printf("%d ",g[i][j]);
	  puts("");
	  }
		
	  puts("");*/
		
	Move4_(point(1,2),Right,Down);
	Move4_(point(1,1),Right,Down);
}

inline void doing()
{
	DREP(i,n,3)DREP(j,m,3)
	{
		int val=(i-1)*m+j;
		point now=point(X[val],Y[val]);
		DREP(k,now.y,2)Move4(now,Left,now.x>1?Up:Down);
		REP(k,now.x,i-1)Move4(now,Down,Right);
		DREP(k,now.x,i+1)Move4(now,Up,Right);
		REP(k,1,j-1)Move4(now,Right,Up);
	}

	DREP(i,n,3)
	{
		int v1=(i-1)*m+1,v2=(i-1)*m+2;
		point now=point(X[v1],Y[v1]);
		DREP(k,now.y,2)Move4(now,Left,now.x>1?Up:Down);
		REP(k,now.x,i-1)Move4(now,Down,Right);
		if(X[v2]==i-1 && Y[v2]==1)
		{
			point now2=point(X[v2],Y[v2]);
			Move4(now2,Right,Up);
			Move4(now,Right,Up);
			now2=point(X[v2],Y[v2]);
			Move4(now2,Right,Up);
			Move4(now,Left,Up);
		}else
		{
			Move4(now,Right,Up);
			now=point(X[v2],Y[v2]);
		
			DREP(k,now.y,2)Move4(now,Left,now.x>1?Up:Down);
			REP(k,now.x,i-2)Move4(now,Down,Right);
			Move4(now,Right,Up);
			
			Move4(now,Down,Left);
		}
	}

	DREP(j,m,3)
	{
		int v1=j,v2=m+j;
		point now=point(X[v1],Y[v1]);
		if(now.x==1)Move4(now,Down,now.y>1?Left:Right);
		REP(k,now.y,j-1)Move4(now,Right,Up);

		if(X[v2]==1 && Y[v2]==j)
		{
			point now2=point(X[v2],Y[v2]);
			Move4(now2,Left,Down);
			Move4(now2,Down,Left);
			Move4(now2,Up,Right);
			Move4(now2,Down,Left);
			Move4(now2,Right,Up);
		}else
		{
			now=point(X[v2],Y[v2]);
			if(now.x==1)Move4(now,Down,now.y>1?Left:Right);
			REP(k,now.y,j-2)Move4(now,Right,Up);
			Move4(now,Right,Up);
		}
	}
	
	while((g[1][1]>2 || g[1][2]>2) && !(g[1][1]==1 && g[2][2]==2))Move4_(point(1,1),Right,Down);

	if(g[1][1]==1 && g[2][2]==2)
	{
		MOVEDOWN();
		Move4_(point(1,1),Right,Down);
	}

	if(Y[m+1]==2)
	{
		//Move4();
		MOVEDOWN();
	}

	if(Y[1]==2)
	{
		MOVEUP();
	}

	printf("%d\n",tot);
	REP(i,1,tot)
	{
		vector<int>v=Ans[i];
		printf("%d ",(int)v.size());
		for(int t:v)printf("%d ",t);
		puts("");
	}
	
	/*REP(i,1,n)
	{
		REP(j,1,m)printf("%d ",g[i][j]);
		puts("");
		}*/
}

// 4 1 2
// 7 6 3
// 8 5 9

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}