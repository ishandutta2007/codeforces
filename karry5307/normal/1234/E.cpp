#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll cnt,ccnt,p,x,y;
ll num[MAXN],diff[MAXN];
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
	cnt=read(),ccnt=read();
	for(register int i=1;i<=ccnt;i++)
	{
		num[i]=read();
	}
	for(register int i=1;i<=ccnt-1;i++)
	{
		if(num[i]!=num[i+1])
		{
			x=num[i],y=num[i+1],p=abs(num[i]-num[i+1]);
			if(x>y)
			{
				swap(x,y);
			}
			diff[1]+=p;
			diff[x]+=(y-1-p);
			diff[x+1]+=p-y;
			diff[y]+=(x-p+1);
			diff[y+1]+=(p-x);
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		diff[i]+=diff[i-1];
		cout<<diff[i]<<" ";
	}
	puts("");
}