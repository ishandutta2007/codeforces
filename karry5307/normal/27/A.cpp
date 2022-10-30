#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=3e3+51;
ll cnt,num;
bool appear[MAXN];
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
int main()
{
    cnt=read();
    for(register int i=0;i<cnt;i++)
    {
        num=read();
        appear[num]=1;
    }
    for(register int i=1;i<MAXN;i++)
    {
        if(!appear[i])
        {
            printf("%d",i);
            return 0;
        }
    }
}