#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,tot;
char ch;
ll num[10];
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
        cin>>ch;
        num[ch-'0']++;
        tot++;
    }
    printf("%d",min(num[8],tot/11));
}