#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll length,kk;
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
int main()
{
	length=read(),kk=read(),cin>>str;
	if(str.length()==1&&kk>=1)
	{
		return puts("0"),0;
	}
	if(str[0]>'1'&&kk)
	{
		str[0]='1',kk--;
	}
	for(register int i=1;i<str.length()&&kk;i++)
	{
		if(str[i]!='0')
		{
			str[i]='0',kk--;
		}
	}
	cout<<str<<endl;
}