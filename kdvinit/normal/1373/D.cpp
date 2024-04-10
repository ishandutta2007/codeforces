/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    long long int a[n+1],sum=0,max1=0,max2=0,cntr1=0,cntr2=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2==1)
        {
            sum+=a[i];
            if(i!=1) cntr1+=a[i-1]-a[i];
        }
        else
        {
            cntr2+=a[i]-a[i-1];
        }

        max1=max(max1,cntr1);
        max2=max(max2,cntr2);

        if(cntr1<0) cntr1=0;
        if(cntr2<0) cntr2=0;
    }

    sum+=max(max1,max2);
    cout<<sum<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}