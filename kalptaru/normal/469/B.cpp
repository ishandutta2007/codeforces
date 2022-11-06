#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int p,q,l,r;
		cin>>p>>q>>l>>r;
		readarr(a,2*p);
		readarr(b,2*q);
		int ar[1001]={0},br[1001]={0},ans=0;
		FOR(k,0,2*p)
		{
			if(k%2==0)
			ar[a[k]]=1;
			else
			ar[a[k]+1]=-1;			
		}
		FOR(k,0,2*q)
		{
			if(k%2==0)
			br[b[k]]=1;
			else
			br[b[k]+1]=-1;			
		}
		FOR(k,1,1001)
		{
			ar[k]+=ar[k-1];
			br[k]+=br[k-1];
		}
		FOR(i,l,r+1)
		{
			FOR(j,0,1001-i)
			{
				if(br[j]==1 && ar[j+i]==1)
				{
					ans++;
					break;
				}
			}
		}
		
		cout<<ans;
	}
}