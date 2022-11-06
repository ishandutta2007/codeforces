#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
/*
//#define FOR(i, a, b) for (int i = (a); i < (b); i++)
//#define readarr(a,n) ll a[(n)+1]; FOR(i, 0, (n)) {cin >> a[i];}
//#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
//#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
//#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}

*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		 int n;
		 cin>>n;
		 vector< ll> brr;
		 vector<ll > crr;	
		 ll arr[n];
		 ll suma=0,sumb=0;
		 for ( int i=0;i<n;i++)
		{	
			int aa;
			cin>>aa;
			arr[i]=aa;
			if ( aa>=0)
			{
				brr.push_back(aa);
				suma+=aa;
			}
			else
			{
				crr.push_back(-aa);
				sumb-=aa;
			}
		}
	//	cout<<suma<<' '<<sumb<<'\n';
		if  ( suma>sumb)
			cout<<"first\n";
		else
		if ( sumb>suma)
			cout<<"second\n";
		else
		{
			bool bo=true;
			for ( int i=0;i<std::min(brr.size(),crr.size());i++)
			{
				if ( brr[i]>crr[i])
				{
					cout<<"first\n";
					bo=false;
					break;
				}
				else
				if ( brr[i]<crr[i])
				{
					cout<<"second\n";
					bo=false;
					break;
				}
			}
			if ( bo)
			{
				if ( brr.size()>crr.size())
				{
					bo=false;
					cout<<"first\n";
				}
				else
				if  ( crr.size()>brr.size())
				{
					bo=false;
					cout<<"second\n";
				}
			}
			if ( bo)
			{
				if ( arr[n-1]<0)
					cout<<"second\n";
				else
					cout<<"first\n";
			}
		}
		
	}
}