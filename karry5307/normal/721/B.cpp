#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,kk,l,c;
string str;
ll len[MAXN];
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
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		cin>>str,len[str.length()]++;	
	}	
	cin>>str,l=str.length();
	for(register int i=1;i<l;i++)
	{
		c+=len[i];
	}
	printf("%d %d\n",c+1+c/kk*5,c+len[l]+(c+len[l]-1)/kk*5);
}