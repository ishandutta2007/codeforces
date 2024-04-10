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

inline int gt(ll x)
{
	int ans=0;
	while(x)
	{
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

int main()
{
	ll n=read(),p=read();
	int cnt=0;
	while(1)
	{
		cnt++;
		ll tmp=n-(cnt)*p;
		if(tmp<=0) {cout<<-1<<endl; break;}
		int tmp2=gt(tmp);
		if(tmp2<=cnt&&tmp>=cnt) {cout<<cnt<<endl; break;}
	}
	return 0;
}