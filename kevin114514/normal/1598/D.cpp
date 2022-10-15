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
ll cnta[200200],cntb[200200];
int a[200200],b[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cnta[i]=cntb[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnta[a[i]]++;
			cin>>b[i];
			cntb[b[i]]++;
		}
		ll ans=1ll*n*(n-1)*(n-2)/6;
		ll ans2=0;
		for(int i=1;i<=n;i++)
			ans2+=(cnta[a[i]]-1)*(cntb[b[i]]-1);
		cout<<ans-ans2<<endl;
	}
	return 0;
}