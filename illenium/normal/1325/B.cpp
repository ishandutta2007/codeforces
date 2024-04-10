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

set <int> s;

int main()
{
	int T=read();;
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
		{
			int x=read();
			s.insert(x);
		}
		printf("%d\n",s.size()); s.clear();
	}
	return 0;
}