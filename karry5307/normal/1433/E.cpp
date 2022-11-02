#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll res[MAXN]={
	0,0,1,2,3,12,40,240,1260,10080,72576,725760,6652800,79833600,889574400,
	12454041600,163459296000,2615348736000,39520825344000,711374856192000,
	12164510040883200
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
int main()
{
	printf("%lld\n",res[read()]);
}