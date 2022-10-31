#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		vector<int> a,b;
		for(int i=1;i<=n*m;i+=2)
		{
			a.push_back(i);
			b.push_back(i+1);
		}
		for(auto z:b)a.push_back(z);
		if(m==1 or n%2==0)
		{
			cout<<"YES"<<endl;
			int ii=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					cout<<a[ii++]<<' ';
				cout<<"\n";
			}
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}