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

int main()
{
	int T=read();
	while(T--)
	{
		int a,b,c,ans=0; cin>>a>>b>>c; ans=0;
		if(a<b) swap(a,b); if(a<c) swap(a,c); if(b<c) swap(b,c);
		if(a!=0) ans++,a--;
		if(b!=0) ans++,b--;
		if(c!=0) ans++,c--;
		if(a!=0&&c!=0) ans++,a--,c--;
		if(a!=0&&b!=0) ans++,a--,b--;
		if(b!=0&&c!=0) ans++,b--,c--;
		if(a!=0&&b!=0&&c!=0) ans++,a--,b--,c--;
		cout<<ans<<endl;
	}
	return 0;
}