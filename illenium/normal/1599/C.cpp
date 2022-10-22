#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline ll C(int N,int M)
{
	ll ans=1; for(ll i=N,j=1;j<=M;j++,i--) ans*=i;
	rep(i,1,M) ans/=i; return ans;
}

double n,p;

inline bool jud(int x)
{
	ll tmp=2*C(x,3)+2*C(x,2)*C(n-x,1)+C(x,1)*C(n-x,2);
	ll P=2*C(n,3);
	if((double)tmp>=(double)P*p) return true; return false;
}

int main()
{
	cin>>n>>p;
	rep(i,0,n) if(jud(i)) {cout<<i<<endl; break;}
}