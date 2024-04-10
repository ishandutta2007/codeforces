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

ll l,r,x,y,ans;

inline void check(ll a)
{
	ll b=x*y/a;
	if(a<l||a>r) return;
	if(b<l||b>r) return;
	if(__gcd(a,b)!=x) return;
	ans++;
}

int main()
{
	cin>>l>>r>>x>>y;
	for(int i=1;i*i<=y;i++)
	{
		if(y%i==0)
		{
			ll p=y/i;
			check(i);
			if(p!=i) check(p);
		}
	}
	printf("%lld\n",ans);
	return 0;
}