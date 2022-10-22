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
#define maxn 200005
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

char mmp[60][60];
 
inline void push(int stx,int enx, int sty, int eny, char str)
{
    for(int i=stx;i<enx;i++)
        for(int j=sty;j<eny;j++)
			mmp[i][j]=str;
}
 
int main()
{
    int a, b, c, d;
	a=read(); b=read(); c=read(); d=read();
    a-=1; b-=1; c-=1; d-=1;
    push(0, 25, 0, 25, 'B');
    push(0, 25, 25, 50, 'A');
    push(25, 50, 0, 25, 'D');
    push(25, 50, 25, 50, 'C');
    
    for(int i = 0; i < 25&&a; i ++)
	{
        for(int j = 0; j < 25&&a; j ++)
		{
            if(i%2 && j%2)
			{
                mmp[i][j] = 'A';
                a --;
            }
        }
    }
    for(int i = 0; i < 25&&b; i ++)
	{
        for(int j = 25; j < 50&&b; j ++)
		{
            if(i%2 == 0 && j%2 == 0)
			{
                mmp[i][j] = 'B';
                b --;
            }
        }
    }
    for(int i = 25; i < 50&&c; i ++)
	{
        for(int j = 0; j < 25&&c; j ++)
		{
            if(i%2 && j%2) {
                mmp[i][j] = 'C';
                c --;
            }
        }
    }
    for(int i = 25; i < 50&&d; i ++)
	{
        for(int j = 25; j < 50&&d; j ++)
		{
            if(i%2 == 0 && j%2 == 0)
			{
                mmp[i][j] = 'D';
                d --;
            }
        }
    }
    printf("50 50\n");
    for(int i=0;i<50;i++)
	{
        for(int j=0;j<50;j++)
			printf("%c", mmp[i][j]);
        puts("");
    }
    return 0;
}