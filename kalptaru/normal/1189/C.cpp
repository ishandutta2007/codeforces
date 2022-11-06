#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int s[n+1];
	for(int i=0;i<n;i++)
	cin>>s[i];
	s[n]=0;
	vector <int> a[n];
	for(int i=0;i<n;i++)
	a[i].push_back(0);
	int i=1,k=0;
	while(i<n)
	{
		for(int j=0;j<(n-i);j++)
		{
			if(s[j]+s[j+i]>=10)
			a[j].push_back(a[j][k]+a[j+i][k]+1);
			else
			a[j].push_back(a[j][k]+a[j+i][k]);
			s[j]=(s[j]+s[j+i])%10;
		}
		i*=2;
		k++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		r=int(log2(r-l+1));
		cout<<a[l-1][r]<<"\n";
	}
	return 0;
}