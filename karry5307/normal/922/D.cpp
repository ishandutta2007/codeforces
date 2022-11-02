#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Item{
	ll r,s,h;
	inline bool operator <(const Item &rhs)const
	{
		return s*rhs.h>h*rhs.s;
	}
};
Item it[MAXN];
ll n,len,s,h,res;
ll f[MAXN][2],suffix[MAXN];
char ch[MAXN];
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
		scanf("%s",ch+1),len=strlen(ch+1),s=h=0;
		for(register int j=1;j<=len;j++)
		{
			f[j][0]=f[j-1][0],f[j][1]=f[j-1][1];
			ch[j]=='s'?s++,f[j][0]++:(h++,f[j][1]+=f[j-1][0]);
		}
		it[i]=(Item){f[len][1],s,h};
	}
	sort(it+1,it+n+1);
	for(register int i=n;i;i--)
	{
		suffix[i]=suffix[i+1]+it[i].h,res+=it[i].r+it[i].s*suffix[i+1];
	}
	printf("%lld\n",res);
}