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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
ll a[300300],b[300300];
ll f[300300];
int cnt;
ll mod;
int n,q;
void modify(int x,int pos,int v)
{
	if(pos>n+1)
		return ;
	if(a[pos]!=b[pos])
		cnt--;
	if(x)
		b[pos]=(b[pos]+v+mod*mod)%mod;
	else	a[pos]=(a[pos]+v+mod*mod)%mod;
	if(a[pos]!=b[pos])
		cnt++;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>q>>mod;
	f[1]=f[2]=1;
	for(int i=3;i<300300;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=2;i<=n+1;i++)
		cin>>a[i];
	for(int i=2;i<=n+1;i++)
		cin>>b[i];
	for(int i=n+1;i>=2;i--)
	{
		a[i]=a[i]-a[i-1]-a[i-2];
		b[i]=b[i]-b[i-1]-b[i-2];
		a[i]+=mod;
		b[i]+=mod;
		a[i]+=mod;
		b[i]+=mod;
		a[i]%=mod;
		b[i]%=mod;
	}
	for(int i=2;i<=n+1;i++)
		if(a[i]!=b[i])
			cnt++;
	while(q--)
	{
		char c;
		cin>>c;
		int l,r;
		cin>>l>>r;
		l++;
		r++;
		if(l==r)
		{
			modify(c=='B',l,1);
			modify(c=='B',l+1,-1);
			modify(c=='B',l+2,-1);
		}
		else
		{
			for(int i=1;i<=2;i++)
				modify(c=='B',i+l-1,f[i]-f[i-1]);
			modify(c=='B',r+1,-f[r-l+2]);
			modify(c=='B',r+2,-f[r-l+1]);
		}
		if(cnt)
			puts("NO");
		else	puts("YES");
	}
	return 0;
}