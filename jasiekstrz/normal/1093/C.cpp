#include<bits/stdc++.h>
using namespace std;
long long w[200010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,b,i;
	cin>>n;
	cin>>b;
	w[n]=b;
	for(i=2;i<=n/2;i++)
	{
		cin>>b;
		if(2*w[n-i+2]-b<b-2*w[i-1])
		{
			w[n-i+1]=w[n-i+2];
			w[i]=b-w[n-i+1];
		}
		else
		{
			w[i]=w[i-1];
			w[n-i+1]=b-w[i];
		}
	}
	for(i=1;i<=n;i++)
		cout<<w[i]<<" ";
	return 0;
}