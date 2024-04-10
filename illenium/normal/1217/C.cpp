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

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];
int len1,pre[maxn],nxt[maxn],last;
ll ans;

inline void sol(int x)
{
	ll cur=1,p,l=x; ans++;
	for(int i=x+1;i<=len1;i++)
	{
		p=cur;
		cur=2*cur+s[i]-'0';
		int t=cur-p; l=l-t; l++;
		//cout<<l<<" "<<cur<<endl;
		if(l<=pre[x]) break;
		else ans++;
	}
	return;
}

int main()
{
	int q=read();
	while(q--)
	{
		scanf("%s",s+1);
		len1=strlen(s+1); last=0;
		for(int i=1;i<=len1;i++) if(s[i]=='1') pre[i]=last,last=i; last=len1+1;
		for(int i=1;i<=len1;i++) if(s[i]=='1') sol(i);
		printf("%lld\n",ans); ans=0;
		memset(pre,0,sizeof(pre));
	}
	return 0;
}