#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

ll f[maxn];
char s[maxn];
ll ans=1;
const ll modc=1e9+7;

int main()
{
	f[1]=1; f[2]=2; f[3]=3;
	for(ll i=4;i<=maxn-5;i++) f[i]=(f[i-1]+f[i-2])%modc;
	scanf("%s",s+1);
	ll len=strlen(s+1),f1=0;
	for(ll i=1;i<=len;i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			puts("0");
			return 0;
		}
	}
	for(ll i=1;i<=len;i++)
	{
		if(s[i]=='u')
		{
			ll cnt=1;
			while(s[i+1]=='u'&&i+1<=len) i++,cnt++;
			ans=(ans*f[cnt])%modc;
		}
		else if(s[i]=='n')
		{
			ll cnt=1;
			while(s[i+1]=='n'&&i+1<=len) i++,cnt++;
			ans=(ans*f[cnt])%modc;
		}
	}
	cout<<ans<<endl;
	return 0;
}