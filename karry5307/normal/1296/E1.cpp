#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e3+51;
ll cnt,l,tot;
ll c[MAXN];
string s;
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
	cnt=read(),cin>>s;
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=i+1;j<cnt;j++)
		{
			for(register int k=j;k<cnt;k++)
			{
				if(s[i]>s[j]&&s[j]>s[k])
				{
					return puts("No"),0;
				}
			}
		}
	}
	puts("Yes");
	for(register int i=0;i<cnt;i++)
	{
		l=0;
		for(register int j=0;j<i;j++)
		{
			if(s[i]<s[j])
			{
				l++;	
				break;
			}	
		}		
		printf("%d",l);
	}
}