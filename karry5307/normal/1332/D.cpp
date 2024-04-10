#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
ll kk;
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
	kk=read();
	printf("2 3\n%d %d 0\n131072 %d %d\n",131072+kk,kk,131072+kk,kk);
}