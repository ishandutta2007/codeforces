#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll n,len;
li res;
ll hv[MAXN];
char ch[MAXN*10];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch+1),len=strlen(ch+1);
		for(register int j=1;j<=len;j++)
		{
			hv[i]^=1<<(ch[j]-'a');
		}
	}
	mp[hv[1]]=1;
	for(register int i=2;i<=n;i++)
	{
		res+=mp[hv[i]];
		for(register int j=0;j<26;j++)
		{
			res+=mp[hv[i]^(1<<j)]; 
		}
		mp[hv[i]]++;
	}
	printf("%lld\n",res);
}