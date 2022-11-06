#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	ll sa[n],sb[n],ea[n],eb[n];
	ll sc[n],sd[n],ec[n],ed[n];
	FOR(i,0,n)
	{
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
		sc[i]=sa[i];
		sd[i]=sb[i];
		ec[i]=ea[i];
		ed[i]=eb[i];
	}
	sort(sc,sc+n);
	sort(sd,sd+n);
	sort(ec,ec+n);
	sort(ed,ed+n);
	FOR(i,0,n)
	{
		int u=(upper_bound(sc,sc+n,ea[i])-sc);
		int r=(lower_bound(ec,ec+n,sa[i])-ec);
		int v=(upper_bound(sd,sd+n,eb[i])-sd);
		int p=(lower_bound(ed,ed+n,sb[i])-ed);
//		cout<<u<<' '<<r<<' '<<v<<' '<<p<<'\n';
		if((u-r)!=(v-p))
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}