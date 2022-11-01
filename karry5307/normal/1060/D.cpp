#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+51;
ll cnt,maxn;
ll l[MAXN],r[MAXN];
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
        l[i]=read(),r[i]=read();
    }
    sort(l,l+cnt),sort(r,r+cnt);
    for(register int i=0;i<cnt;i++)
    {
        maxn+=max(l[i],r[i]);
    }
    printf("%I64d",maxn+cnt);
}