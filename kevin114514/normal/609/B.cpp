#include<bits/stdc++.h>
using namespace std;
long long ans,cnt[11];
int main()
{
	int N,M;
	cin>>N>>M;
	while(N--)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=M;i++)
		for(int j=1;j<i;j++)
			ans+=cnt[i]*cnt[j];
	cout<<ans<<endl;
	return 0;
}