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

int mp[3][maxn],n,q;

inline int s(int x,int y)
{
	int ans=0; x=3-x;
	if(mp[x][y]) ans++;
	if(mp[x][y-1]) ans++;
	if(mp[x][y+1]) ans++;
	return ans;
}

int main()
{
	n=read(); q=read(); int tmp=0;
	while(q--)
	{
		int x=read(),y=read();
		if(!mp[x][y]) tmp+=s(x,y);
		else tmp-=s(x,y);
		mp[x][y]=!mp[x][y];
		if(tmp>0) puts("No");
		else puts("Yes");
	}
	return 0;
}