#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define iter iterator  
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,st,ed,res;
string str;
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
inline void solve()
{
	cin>>str,res=0,st=ed=-1;
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]=='1')
		{
			st=i;
			break;
		}
	}
	for(register int i=str.length()-1;i>=0;i--)
	{
		if(str[i]=='1')
		{
			ed=i;
			break;
		}
	}
	if(st==-1&&ed==-1)
	{
		return (void)(puts("0"));
	}
	for(register int i=st;i<=ed;i++)
	{
		res+=49-str[i];
	}
	printf("%d\n",res);
	
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}