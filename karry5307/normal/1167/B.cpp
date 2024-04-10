#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll flg;
ll p[7]={0,4,8,15,16,23,42},r[7];
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
	cout<<"? 1 2"<<endl,r[2]=read();
	cout<<"? 2 3"<<endl,r[3]=read();
	cout<<"? 3 4"<<endl,r[4]=read();
	cout<<"? 4 5"<<endl,r[5]=read();
	do
	{
		flg=1;
		for(register int i=2;i<=5;i++)
		{
			if(p[i-1]*p[i]!=r[i])
			{
				flg=0;
				break;
			}
		}
		if(flg)
		{
			cout<<"! ";
			for(register int i=1;i<=6;i++)
			{
				cout<<p[i]<<" ";
			}
			return cout<<endl,0;
		}
	}
	while(next_permutation(p+1,p+7));
}