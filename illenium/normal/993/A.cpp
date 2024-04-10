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

struct point{int x;int y;}sq[4],sp[4];

inline bool cmp(point a,point b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int t[220][220];

inline void tian(point a,point b)
{
    for(int i = a.x;i <= b.x; ++i){
        for(int j = a.y;j <= b.y; ++j){
            t[i][j] = 1;
        }
    }
}

inline bool judge(point* sp)
{
    for(int i = sp[0].x;i <= sp[1].x; ++i){
        for(int j = 0;j <= i-sp[0].x; ++j){
            if(t[i][sp[0].y+j] == 1||t[i][sp[0].y-j] == 1){
                return true;
            }
        }
    }
    for(int i = sp[1].x;i <= sp[3].x; ++i){
        for(int j = 0;j <= sp[2].y-sp[0].y-(i-sp[1].x); ++j){
            if(t[i][sp[0].y+j] == 1||t[i][sp[0].y-j] == 1){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    for(int i=0;i<4;++i) sq[i].x=read(),sq[i].y=read(),sq[i].x+=100,sq[i].y+=100;
    for(int i=0;i<4;++i) sp[i].x=read(),sp[i].y=read(),sp[i].x+=100,sp[i].y+=100; 
    sort(sq,sq+4,cmp); sort(sp,sp+4,cmp);
    tian(sq[0],sq[3]);
    if(judge(sp)) puts("YES");
    else puts("NO");
    return 0;
}