#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;

ll a[55][55];

int main()
{
	ll n,nw=1; cin>>n;
	rep(i,1,n)
	{
		ll tmp=nw;
		for(ll j=2;j<=n;j+=2) a[i][j]=tmp,tmp*=4;
		nw*=2;
	}
	rep(i,1,n)
	{
		rep(j,1,n) cout<<a[i][j]<<" ";
		puts("");
	}
	ll Q; cin>>Q;
	while(Q--)
	{
		ll k,nx=1,ny=1; cin>>k;
		for(ll i=0;i<=60;i++)
		{
			cout<<nx<<" "<<ny<<endl;
			if(k&((1ll)<<i))
			{
				if(a[nx][ny]) nx++;
				else ny++;
			}
			else
			{
				if(a[nx][ny]) ny++;
				else nx++;
			}
			if(ny==n+1||nx==n+1) break;
		}
		if(nx==n+1) rep(i,ny+1,n) cout<<n<<" "<<i<<endl;
		else if(ny==n+1) rep(i,nx+1,n) cout<<i<<" "<<n<<endl;
	}
	return 0;
}