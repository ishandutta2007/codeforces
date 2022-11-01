#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cnt,maxn=1,first;
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
inline ll calc(ll num)
{
    ll res=0;
    while(num)
    {
        res+=(num%10),num/=10;
    }
    return res;
}
int main()
{
    cnt=read();
    while(maxn<=cnt)
    {
        maxn*=10;
    }
    maxn/=10;
    first=cnt/maxn;
    cout<<calc(first*maxn-1)+calc(cnt-first*maxn+1);
}