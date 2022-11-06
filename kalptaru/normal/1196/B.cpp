#include <bits/stdc++.h>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
int main()
{
	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		int n,k,v;
		cin>>n>>k;
		v=k;
		readarr(a,n);
		ll g=0;
		vector <ll> h;
		bool f=1;
		FOR(i,0,n)
		{
			if(a[i]%2==1)
			{
				h.push_back(i+1);
				g=0;
				k--;
			}
		}
		if(k>0 || (k+1000000)%2==1)
		cout<<"NO \n";
		else
		{
			cout<<"YES \n";
			FOR(i,0,v-1)
			cout<<h[i]<<' ';
			cout<<n<<"\n";
		}
	}
	return 0;
}