#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int l[30]={0};
		int n;
		ll k,h;
		cin>>n;
		FOR(i,0,n)
		{
			cin>>k;
			h=log2(k);
			l[h]++;
		}
		bool f=1;
		int p=0;
		while(p<11)
		{
			l[p+1]+=(l[p]/2);
			p++;
		}
		if(l[11]>0)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}