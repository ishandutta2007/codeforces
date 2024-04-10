#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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
vector <int> vec;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); scanf("%s",s+1);
		int tmp=0,f=n+1; vec.clear();
		for(int i=1;i<=n;i++)
		{
			if((s[i]-'0')%2==1) vec.push_back(s[i]-'0');
			if(vec.size()==2) break;
		}
		if(vec.size()<2) puts("-1");
		else printf("%d%d\n",vec[0],vec[1]);
	}
	return 0;
}