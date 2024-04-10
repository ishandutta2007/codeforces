#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,k,i,j,l;
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>n>>k;
		for(j=0;j<k;j++)
		{
			for(l=1;l<=(n/k);l++)
				cout<<(char)('a'+j);
			if(j<n%k)
				cout<<(char)('a'+j);
		}
		cout<<"\n";
	}
	return 0;
}