#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
struct g
{
	int t;
	int p;
	int x;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		readarr(a,n);
		int q;
		cin>>q;
		g h[q],k;
		bool sq[n+1]={0};
		FOR(i,0,q)
		{
			cin>>k.t;
			if(k.t==1)cin>>k.p>>k.x;
			else{k.p=0;cin>>k.x;}
			h[i]=k;
		}
		ll m=0;
		FOR(i,1,q+1)
		{
			k=h[q-i];
			if(k.t==1)
			{
				if(sq[k.p]==0)
				{
					if(k.x>m)
					{
						a[k.p]=k.x;
						sq[k.p]=1;
					}
					else
					{
						a[k.p]=m;
						sq[k.p]=1;
					}
				}
			}
			else
			{
				if(k.x>m)
				m=k.x;
			}
		}
		FOR(i,1,n+1)
		{
			if(sq[i]==0 && a[i]<m)
			a[i]=m;
		}
		printarr(a,1,n);
	}
}