#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
const int N=3e5+5;
typedef long long ll;
int xl=6,xr=10,yl=8,yr=30;
int query(int x,int y)
{
    // int ret=2e9;
    // for(int i=xl;i<=xr;i++)
    //     for(int j=yl;j<=yr;j++)
    //     ret=min(ret,abs(x-i)+abs(y-j));
    // return ret;
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int ans=0;
    scanf("%d",&ans);
    return ans;
}
int main()
{
    int d1=query(1,1),d3=query(1,1000000000);
    int d2=query(1000000000,1),d4=query(1000000000,1000000000);
    int x1=1,y1=1,x2=1,y2=1000000000,x3=1000000000,y3=1,x4=1000000000,y4=1000000000;
    if(d1>d2) x1+=d1-d2,x2+=d1-d2;
    else x3-=d2-d1,x4-=d2-d1;
    if(d1>d3) y1+=d1-d3,y3+=d1-d3;
    else y2-=d3-d1,y4-=d3-d1;
    int a=query((x1+x3)/2,y1);
    int b=query(x1,(y1+y2)/2);
    printf("! %d %d %d %d\n",x1+b,y1+a,x4-b,y4-a);
}