#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 5005
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

int a[maxn];
vector <int> vec[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),f=0;
		for(int i=1;i<=n;i++) a[i]=read(),vec[a[i]].push_back(i);
		for(int i=1;i<=n;i++)
		{
			if(vec[i].size()>=2)
			{
				int s=vec[i][0],t=vec[i][vec[i].size()-1];
				if(t-s>=2) {f=1; break;}
			}
		}
		if(f==1) puts("YES"); else puts("NO");
		for(int i=1;i<=n;i++) vec[i].clear();
	}
	return 0;
}