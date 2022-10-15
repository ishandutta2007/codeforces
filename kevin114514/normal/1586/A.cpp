#include<bits/stdc++.h>
using namespace std;
bool isp[20020];
int x[110];
map<int,int> Mp;
int main()
{
	for(int i=2;i<20020;i++)
		if(!isp[i])
			for(int j=i*i;j<20020;j+=i)
				isp[j]=1;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			sum+=x[i];
			Mp[x[i]]=i;
		}
		Mp[0]=n;
		x[n]=0;
		sort(x,x+n+1);
		for(int i=0;i<=n;i++)
			if(isp[sum-x[i]])
			{
				cout<<n-min(1,x[i])<<endl;
				for(int j=0;j<n;j++)
					if(j!=Mp[x[i]])
						cout<<j+1<<" ";
				puts("");
				break;
			}
	}
}