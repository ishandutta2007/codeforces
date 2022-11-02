#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll r,g;
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
    r=read();
    while(r)
    {
        if(r%8==1)
        {
            g++;
        }
        r/=8;
    }
    printf("%d",g);
}