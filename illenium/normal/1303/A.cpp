#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1),f1=0,f2=0,ans=0;
		for(int i=1;i<=len;i++) if(s[i]=='1') {f1=i; break;}
		for(int i=len;i>=1;i--) if(s[i]=='1') {f2=i; break;}
		for(int i=f1;i<=f2;i++) if(s[i]=='0') ans++;
		cout<<ans<<endl;
	}
	return 0;
}