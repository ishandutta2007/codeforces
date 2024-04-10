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
		int n,k,d;
		cin>>n>>k>>d;
		ll adp[n+2]={0},ddp[n+2]={0},r=1000000007;
		adp[0]=1;
		FOR(i,1,n+1)
		{
			int j=1;
			while(j<=k && i-j>=0)
			{
				adp[i]+=adp[i-j];
				j++;
			}
			j=1;
			while(j<d && i-j>=0)
			{
				ddp[i]+=ddp[i-j];
				j++;
			}
			while(j<=k && i-j>=0)
			{
				ddp[i]+=adp[i-j];
				j++;
			}
			adp[i]=adp[i]%r;
			ddp[i]=ddp[i]%r;
		}
		cout<<ddp[n];
	}
}