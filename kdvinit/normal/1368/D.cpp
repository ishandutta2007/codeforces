/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n;
	cin>>n;
	int freq[20]={0};

	for(int i=1;i<=n;i++)
    {
        int x,cntr=0;
        cin>>x;
        while(x!=0)
        {
            if(x%2==1) freq[cntr]++;
            cntr++;
            x/=2;
        }
    }

	long long int a[n+1]={0},cntr=1;
	for(int i=0;i<20;i++)
    {
        for(int j=1;j<=freq[i];j++)
        {
            a[j]+=cntr;
        }
        cntr*=2;
    }

    long long int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i]*a[i];

	cout<<ans<<endl;
	return 0;
}