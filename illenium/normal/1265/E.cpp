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
#define p 998244353
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll dp[maxn],a[maxn];

inline ll qpow(int a,int b)
{
    ll base=a,ans=1;
    while(b)
    {
        if(b&1) ans=(ans*base)%p;
        base=(base*base)%p; b>>=1;
    }
    return ans;
}

int main()
{
	ll n=read();
	for(int i=1;i<=n;i++) a[i]=read(); dp[0]=1;
	for(int i=1;i<=n;i++) dp[i]=((dp[i-1]*100)%p*qpow(a[i],p-2))%p+1;
    cout<<(dp[n]+p-1)%p<<endl;
	return 0;
}