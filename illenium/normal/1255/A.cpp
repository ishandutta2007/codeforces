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

int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read();
		if(a>b) swap(a,b);
		int ans=0;
		ans+=(b-a)/5;
		if((b-a)%5==1) cout<<ans+1<<endl;
		else if((b-a)%5==2) cout<<ans+1<<endl;
		else if((b-a)%5==3) cout<<ans+2<<endl;
		else if((b-a)%5==4) cout<<ans+2<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}