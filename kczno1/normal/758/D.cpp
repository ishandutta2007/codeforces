#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=105,D=1e9+7;
ll n;char s[N];
ll ans=0,base=1,now=0,mi10=1;
int i;
void clear()
{
	ans+=now*base;
	base*=n;
}

int main()
{
     scanf("%d%s",&n,s+1);
     int len=strlen(s+1);
     for(i=len;i;--i)
     {
     	now+=(s[i]-'0')*mi10;
		if(now>=n) 
		{now%=mi10;
		 if(now)clear();
	
		 mi10=1;now=s[i]-'0';
		 
		 int j=i+1;
		 while(s[j]=='0')++j;
		 int cnt=j-i-1;
		 
		  while(cnt&&now*mi10*10<n){--cnt;mi10*=10;}
		  now*=mi10;
		  while(cnt--)base*=n;
		}  
		mi10*=10;
     }
     clear();
     printf("%lld\n",ans);
}