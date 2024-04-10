#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,a[200005];
int c[35];
void solve()
{
	int i,j;
	memset(c,0,sizeof(c));
	
	cin>>n;
	rep(i,n) cin>>a[i];
	
	rep(i,n)
	{
		for(j=0;j<30;j++) if((a[i]>>j)&1) c[j]++;
	}
	
	int g=0;
	for(j=0;j<30;j++) g=__gcd(g,c[j]);
	
	rep(i,n) if(g%i==0) printf("%d ",i);
	puts("");
}


int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}