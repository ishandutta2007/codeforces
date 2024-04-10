#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll len,cur,res;
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
	cin>>s,s+=s,len=s.length(),cur=res=1;
	for(register int i=1;i<len;i++)
	{
		s[i]!=s[i-1]?cur++:(res=max(res,cur),cur=1);
	}
	res=max(res,cur),printf("%d\n",min(res,len/2));
}