#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,l=0,r=1e9,mid;
string cur,first;
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
    puts("0 2");
    cin>>first;
    for(register int i=1;i<cnt;i++)
    {
        mid=(l+r)>>1;
        printf("%d 2\n",mid);
        cin>>cur;
        cur==first?l=mid:r=mid;
    }
    printf("%d 0 %d 4",l,r);
}