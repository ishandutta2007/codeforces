#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i-1];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll ans=0,r=1000003,m=1;
		int n=s.size(),y;
		map<char,int> c;
		c.insert(pair<char,int>('>',8));
		c.insert(pair<char,int>('<',9));
		c.insert(pair<char,int>('+',10));
		c.insert(pair<char,int>('-',11));
		c.insert(pair<char,int>('.',12));
		c.insert(pair<char,int>(',',13));
		c.insert(pair<char,int>('[',14));
		c.insert(pair<char,int>(']',15));
		FOR(i,1,n+1)
		{
			ans+=(m*c[s[n-i]]);
			ans=ans%r;
			m*=16;
			m=m%r;
		}
		cout<<ans;
	}
}