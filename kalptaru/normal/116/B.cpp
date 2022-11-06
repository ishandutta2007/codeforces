#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) char a[(n+2)][(m+2)]={}; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,m,ans=0;
		cin>>n>>m;
		readmat(a,n,m);
		FOR(i,1,n+1)
		{
			FOR(j,1,m+1)
			{
				if(a[i][j]=='W')
				{
					if(a[i-1][j]=='P' || a[i+1][j]=='P' || a[i][j-1]=='P' || a[i][j+1]=='P')
					ans++;
				}
			}
		}
		cout<<ans;
		
	}
}