#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,cnt,num;
ll occ[31];
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
	test=read();
	for(register int i=0;i<test;i++)
	{
		cnt=read();
		for(register int j=0;j<cnt;j++)
		{
			num=read(),occ[(ll)log2(num)]++;
		}
		for(register int j=0;j<11;j++)
		{
			if(occ[j]>=2)
			{
				occ[j+1]+=occ[j]>>1,occ[j]&=1;
			}
		}
		puts(occ[11]?"Yes":"No");
		memset(occ,0,sizeof(occ));
	}
}