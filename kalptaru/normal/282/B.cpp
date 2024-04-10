#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,n) FOR(i, 1, (n)+1) {cout<< a[i];}
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
		int n,a,g,d=0;
		cin>>n;
		char b[n+1];
		FOR(i,1,n+1)
		{
			cin>>a>>g;
			if(a+d<=500)
			{
				b[i]='A';
				d+=a;
			}
			else
			{
				b[i]='G';
				d-=g;
			}
		}
		printarr(b,n);
	}
}