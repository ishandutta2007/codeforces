/*
K.D. Vinit
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n;
	cin>>n;

	int a[n+1],sum=0;
	for(int i=1;i<=n;i++)
	{
	    int x;
	    cin>>x;
	    if(x==1) a[++sum]=i;
    }

	if(sum==1) { cout<<-1<<endl; return 0; }

    int prime[sum+1];
    for(int i=0;i<=sum;i++) prime[i]=1;
    for(int i=2;i*i<=sum;i++)
    {
        if(prime[i]==1) for(int j=i*i;j<=sum;j+=i) prime[j]=0;
    }

	long long ans=10000000000;
	for(int i=2;i<=sum;i++)
    {
        if(prime[i]==0 || sum%i!=0) continue;
        int m=(sum/i),l=i,k=((i+1)/2);
        long long int temp=0;
        for(int j=0;j<m;j++)
        {
            int y=a[j*i+k];
            for(int i2=1;i2<=i;i2++)
            {
                temp+=abs(a[j*i+i2]-y);
            }
        }
        ans=min(ans,temp);
    }

    cout<<ans<<endl;
	return 0;
}