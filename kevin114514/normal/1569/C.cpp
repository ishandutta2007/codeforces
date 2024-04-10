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
int a[200200];
ll fact[200200];
const ll mod=998244353;
ll ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	return ksm(a*a%mod,b/2)*(b%2?a:1)%mod;
}
ll inv(ll x)
{
	return ksm(x,mod-2);
}
int main()
{
	fact[0]=1;
	for(int i=1;i<=200000;i++)
		fact[i]=fact[i-1]*i%mod;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int number=0;
		for(int i=n-2;i>=0;i--)
			if(a[i]==a[n-2])
				number++;
		if(a[n-1]==a[n-2])
			cout<<fact[n]<<endl;
		else if(a[n-1]-1>a[n-2])
			cout<<0<<endl;
		else	cout<<fact[n]*inv(number+1)%mod*number%mod<<endl;
	}
	return 0;
}