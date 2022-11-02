#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll r,g;
char ch;
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
    r=read(),g=read();
    for(register int i=0;i<r;i++)
    {
        for(register int j=0;j<g;j++)
        {
            cin>>ch;
            if(ch=='C'||ch=='M'||ch=='Y')
            {
                printf("#Color");
                return 0;
            }
        }
    }
    printf("#Black&White");
}