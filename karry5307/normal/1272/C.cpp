#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll length,cnt,res,cur;
string str;
char ch;
ll mp[128];
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
	length=read(),cnt=read(),cin>>str;
	for(register int i=0;i<cnt;i++)
	{
		cin>>ch,mp[ch]=1;
	}
	for(register int i=0;i<length;i++)
	{
		if(mp[str[i]]==1)
		{
			cur++;
		}
		else
		{
			res+=1ll*cur*(cur+1)/2,cur=0;
		}
	}
	res+=1ll*cur*(cur+1)/2,printf("%lld\n",res);
}