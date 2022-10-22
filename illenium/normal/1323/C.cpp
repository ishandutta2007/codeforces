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
int c1,c2,ans,n,f;
stack <int> S;

int main()
{
	n=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(') c1++;
		else c2++;
	}
	if(c1!=c2) {puts("-1"); return 0;}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			if(f==0) S.push(i);
			else f--,ans++;
		}
		else
		{
			if(S.size()==0) ans++,f++;
			else S.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}