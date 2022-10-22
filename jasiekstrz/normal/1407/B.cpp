#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int tab[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,i;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>tab[i];
		int gcd=tab[1];
		for(i=1;i<=n;i++)
			gcd=max(gcd,tab[i]);
		for(i=1;i<=n;i++)
		{
			if(tab[i]==gcd)
			{
				tab[i]=0;
				break;
			}
		}
		cout<<gcd<<" ";
		for(i=2;i<=n;i++)
		{
			int a=1;
			for(int j=1;j<=n;j++)
			{
				if(tab[j]>0)
					a=max(a,__gcd(gcd,tab[j]));
			}
			for(int j=1;j<=n;j++)
			{
				if((tab[j]>0)&&(__gcd(gcd,tab[j])==a))
				{
					cout<<tab[j]<<" ";
					tab[j]=0;
					break;
				}
			}
			gcd=a;
		}
		cout<<"\n";
	}
	return 0;
}