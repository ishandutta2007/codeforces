#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,cur,divs;
ll ball[3],res[6][6]={
    0,1,2,2,1,0,
    1,0,0,1,2,2,
    2,2,1,0,0,1
};
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll calc(ll p,ll cur)
{
    if((p==0&&cur==0)||(p==1&&cur==1)||(p==2&&cur==2)||(p==3&&cur==2)||(p==4&&cur==1)||(p==5&&cur==0))
    {
        return 0;
    }
    if((p==0&&cur==1)||(p==1&&cur==0)||(p==2&&cur==0)||(p==3&&cur==1)||(p==4&&cur==2)||(p==5&&cur==2))
    {
        return 1;
    }
    if((p==0&&cur==2)||(p==1&&cur==2)||(p==2&&cur==1)||(p==3&&cur==0)||(p==4&&cur==0)||(p==5&&cur==1))
    {
        return 2;
    }
}
int main()
{
    cnt=read(),cur=read();
    cnt%=6;
    printf("%d",calc(cnt,cur));
}