#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,n) FOR(i, 1, (n)+1) {cout<< a[i]<<' ';}
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
		int d,s,e=0,r=0,f;
		cin>>d>>s;
		int a[d][2];		
		FOR(i,0,d)
		{
			cin>>a[i][0]>>a[i][1];
			e+=a[i][0];
			r+=a[i][1];
		}
		if(e<=s && s<=r)
		{
			f=s-e;
			cout<<"YES\n";
			FOR(i,0,d)
			{
				if(f>=(a[i][1]-a[i][0]))
				{
					cout<<a[i][1]<<' ';
					f-=(a[i][1]-a[i][0]);
				}
				else
				{
					cout<<a[i][0]+f<<' ';
					f=0;
				}
			}
		}
		else
		cout<<"NO";
	}
}