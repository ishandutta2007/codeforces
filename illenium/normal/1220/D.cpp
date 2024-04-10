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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll mp[maxn],ans,flag,p[maxn],q[maxn];

int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		ll x=read(),cnt=0; q[i]=x;
		while(x%2==0) x>>=1,cnt++;
		mp[cnt]++; p[i]=cnt;
		if(ans<mp[cnt]) ans=mp[cnt],flag=cnt;
	}
	cout<<n-ans<<endl;
	for(int i=1;i<=n;i++) if(p[i]!=flag) cout<<q[i]<<" ";
	return 0;
}