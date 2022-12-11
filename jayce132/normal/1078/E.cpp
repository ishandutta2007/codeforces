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

int cell[1000][1000];

#define C(x,y) cell[(x)+500][(y)+500]

int n=32;

int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

char s[4]={'r','d','u','l'};

#define Right 0
#define Down 1
#define Up 2
#define Left 3

int sx,sy;

int A,B;

inline void prepare()
{
	memset(cell,-1,sizeof(cell));
	int t=0;
	while(A)C(-1,-t)=A%2,A>>=1,t++;
	t=0; while(B)C(0,-t)=B%2,B>>=1,t++;
}

inline void move_if_1(int turn)
{
	int turno=3-turn;
	printf("%c%cst",s[turn],s[turno]);
	if(C(sx,sy)==1)sx+=d[turn][0],sy+=d[turn][1];
}

inline void move_if_0(int turn)
{
	int turno=3-turn;
	printf("%c%ct",s[turn],s[turno]);
	
	if(C(sx,sy)==0)sx+=d[turn][0],sy+=d[turn][1];
}

inline void move_if_notempty(int turn)
{
	int turno=3-turn;
	printf("%cs%ct",s[turn],s[turno]);
	
	if(C(sx,sy)!=-1)sx+=d[turn][0],sy+=d[turn][1];
}

inline void copy(int turn)//0,1 copy ; empty -> add 0 
{
	int turno=3-turn;
	printf("%c10%ct",s[turn],s[turno]);
	int tmp=C(sx,sy);
	if(~tmp)sx+=d[turn][0],sy+=d[turn][1],C(sx,sy)=tmp;
	else
	{
		int vx=sx+d[turn][0],vy=sy+d[turn][1];
		C(vx,vy)=0;
	}
}
inline void put(int x)
{
	printf("%d",x);
	C(sx,sy)=x;
}

inline void erase(){ printf("e"); C(sx,sy)=-1;}

inline void move(int turn){ printf("%c",s[turn]); sx+=d[turn][0]; sy+=d[turn][1];}

inline int Num(int x,int y){ return cell[x+500][y+500];}

int N=32;


inline void init()
{
	move(Down);REP(i,0,N-1)move(Right),put(1); DREP(i,N-1,0)move(Left); move(Up);
	Num(1,1);
	REP(i,0,N-1)move_if_notempty(Left); put(0); REP(i,0,N-1)copy(Left);
	REP(i,0,2*N)move_if_notempty(Right); move(Up); move(Left);

	REP(i,0,N-1)move_if_notempty(Left); put(0); REP(i,0,N-1)copy(Left);
	REP(i,0,2*N)move_if_notempty(Right); move(Up);move(Left); put(0);

	
	REP(i,0,N-1)
	{
		move(Up); put(0); move(Right); put(1); move(Right); put(0); move(Right); put(1);
		move(Left); move(Left); move(Left); move(Down); copy(Right); copy(Right); copy(Right);
		move(Left); move(Left); move(Left); move(Down); copy(Right); copy(Right); copy(Right);
		move(Left); move(Left); move(Left); move(Down); copy(Right); copy(Right); copy(Right);

		move(Left); move(Left); move(Left);

		move_if_1(Right); move(Up);
		move_if_1(Right); move(Up);
		move_if_1(Right); move(Up);
		copy(Right); copy(Down);copy(Down);copy(Down);copy(Down);

		REP(i,0,6)move_if_notempty(Left),move_if_notempty(Right),copy(Left);
		move(Left); erase(); move(Right); move(Right); copy(Left); copy(Down);
		move(Up); move(Up); move(Up); move(Up); 
		move(Up); put(0); move(Right); put(0); move(Right); put(1); move(Right); put(1);
		move(Left); move(Left); move(Left); move(Down); copy(Right); copy(Right); copy(Right);
		move(Left); move(Left); move(Left); move(Down); copy(Right); copy(Right); copy(Right);
		move(Left); move(Left); move(Left); move(Down); copy(Right); copy(Right); copy(Right);
		move(Left); move(Left); move(Left);

		move_if_1(Right); move(Up);
		move_if_1(Right); move(Up);
		move_if_1(Right); move(Up);

		REP(i,0,6)move_if_notempty(Left),move_if_notempty(Right),copy(Left);
		move(Left); erase(); move(Right); move(Right); copy(Left); copy(Down);
		
	}
	move(Down); move(Down); move(Down);move(Down);move(Right);
	/*puts("");
	printf("%d %d\n",sx,sy);
	unsigned ans=0;
	while(C(sx,sy)!=-1)
	{
		ans=ans*2+C(sx,sy);
		sx+=d[Right][0]; sy+=d[Right][1];
	}
	printf("%u\n",ans);*/
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read();A=read();B=read();
	prepare();
	init();
	return 0;
}