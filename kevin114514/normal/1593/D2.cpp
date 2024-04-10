#include<bits/stdc++.h>
using namespace std;
int x[44];
int n;
map<int,int> Mp;
int calc(int a,int b)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		if((a-x[i])%b==0)
			cnt++;
	return cnt;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		Mp.clear();
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			Mp[x[i]]++;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(Mp[x[i]]>=n/2)
				ans=-1;
		}
		if(ans==-1)
		{
			puts("-1");
			continue;
		}
		sort(x,x+n);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int del=x[j]-x[i];
				if(!del)
					continue;
				for(int k=1;k<=sqrt(del);k++) if(del%k==0)
				{
					if(calc(x[i],k)>=n/2)
						ans=max(ans,k);
					if(calc(x[i],del/k)>=n/2)
						ans=max(ans,del/k);
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}