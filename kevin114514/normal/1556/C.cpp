#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll x[1010];
ll psum[1010];
ll a[1010][1010],b[1010][1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(i%2==0)
			x[i]*=-1;
		psum[i]=psum[i-1]+x[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			a[i][j]=max(a[i][j-1],-(psum[j]-psum[i-1]));
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
			b[i][j]=max(b[i][j+1],(psum[i]-psum[j-1]));
	ll ans=0;
	for(int i=1;i<=n;i++) if(i%2)
		for(int j=i+1;j<=n;j++) if(j%2==0)
		{
			ll A=-(psum[j-1]-psum[i]);//x-y
			ll B=a[i+1][j-1];//x>=...
			ll C=b[j-1][i+1];//y>=...
			B=max(B,1ll);
			C=max(C,1ll);
			ll U=min(x[i],-x[j]+A);
//			cout<<i<<" "<<j<<" "<<A<<" "<<B<<" "<<C<<" "<<U<<endl;
			B=max(B,C+A);
			ans+=max(0ll,U-B+1);
		}
	cout<<ans<<endl;
	return 0;
}