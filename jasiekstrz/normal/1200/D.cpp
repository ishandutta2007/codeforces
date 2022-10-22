#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
bool tab[2010][2010];
int pom[2010][2010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,l,r,p,m,plus=0,w,a,i,j;
	char c;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>c;
			tab[i][j]=(c=='B');
		}
	}
	for(i=1;i<=n;i++)
	{
		l=0;
		r=0;
		for(j=1;j<=n;j++)
		{
			if(tab[i][j])
			{
				r=j;
				if(l==0)
					l=j;
			}
		}
		if(l==0)
			plus++;
		else
		{
			p=max(1,r-k+1);
			m=l+1;
			//cerr<<p<<" "<<m<<"\n";
			if(p<m)
			{
				for(j=max(1,i-k+1);j<=i;j++)
				{
					pom[j][p]++;
					pom[j][m]--;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		l=0;
		r=0;
		for(j=1;j<=n;j++)
		{
			if(tab[j][i])
			{
				r=j;
				if(l==0)
					l=j;
			}
		}
		if(l==0)
			plus++;
		else
		{
			p=max(1,r-k+1);
			m=l+1;
			//cerr<<p<<" "<<m<<"\n";
			for(j=p;j<m;j++)
			{
				pom[j][max(1,i-k+1)]++;
				pom[j][i+1]--;
			}
		}
	}
	w=0;
	for(i=1;i<=n;i++)
	{
		a=0;
		for(j=1;j<=n;j++)
		{
			//cerr<<pom[i][j]<<" ";
			a+=pom[i][j];
			w=max(w,a);
		}
		//cerr<<"\n";
	}
	cout<<w+plus;
	return 0;
}