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

ll a,b,c,d,e,f,ans;

int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	ll tmp1,tmp2;
	for(ll i=0;i<=d;i++)
	{
		ll tmp1=min(a,i),tmp2=min(b,min(c,d-i));
		ans=max(ans,tmp1*e+tmp2*f);
	}
	cout<<ans<<endl;
	return 0;
}