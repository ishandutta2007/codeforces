#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
unordered_map<li,ll>mp;
ll cnt,kk,res;
li hsh[MAXN];
string str[MAXN];
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
inline ll encode(char ch)
{
	return ch=='S'?0:ch=='E'?1:2;
}
inline void calc(ll x,ll y)
{
	li h=0;
	for(register int i=0;i<kk;i++)
	{
		h*=3;
		if(str[x][i]==str[y][i])
		{
			h+=encode(str[x][i]);
		}
		else
		{
			h+=3-encode(str[x][i])-encode(str[y][i]);
		}
	}
	res+=mp[h];
}
int main()
{
	cnt=read(),kk=read();
	for(register int i=0;i<cnt;i++)
	{
		cin>>str[i];
		for(register int j=0;j<kk;j++)
		{
			hsh[i]=hsh[i]*3+encode(str[i][j]);
		}
		mp[hsh[i]]=1;
	}
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=i+1;j<cnt;j++)
		{
			calc(i,j);
		}
	}
	printf("%d\n",res/3);
}