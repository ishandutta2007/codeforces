#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
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
		int n,h=0;
		cin>>n;
		readarr(a,n)
		ll s=0,p[n+1],ans=0;
		FOR(i,1,n+1)
		{
			s+=a[i];
			p[i]=s;
		}
		if(s==0)
		{
			FOR(i,0,n)
			{
				if(p[n-i]==0)
				{
					ans+=h;
					h++;
				}
			}
			cout<<ans-h+1;
		}
		else if(s%3==0)
		{
			s=s/3;
			FOR(i,0,n)
			{
				if(p[n-i]==s)
				ans+=h;
				else if(p[n-i]==2*s)
				h++;
			}
			cout<<ans;
		}
		else
		cout<<0;
		
	}
}