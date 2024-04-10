#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(n) push_back((n));
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int cnt=0,sk=k-1;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(cnt%2==0 && k>1)
				{
					cout<<"\n"<<2<<' ';
					k--;
				}
				else if(cnt%2==0 && k==1)
				{
					cout<<"\n"<<n*m-2*sk<<' ';
					k--;
				}
				if(i%2==0)
				cout<<i+1<<' '<<j+1<<' ';
				else
				cout<<i+1<<' '<<m-j<<' ';
				cnt++;
			}
		}
	}
}