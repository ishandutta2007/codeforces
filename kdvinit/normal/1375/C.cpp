/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n;
    cin>>n;

    long long int a[n+1];
    for(long long int i=1;i<=n;i++) cin>>a[i];

    long long int val=0;
    for(long long int i=1;i<=n;i++)
    {
        if(i==1)
        {
            val=a[i];
            continue;
        }
        if(a[i-1]<a[i]) continue;
        else
        {
            while(1)
            {
                if(i==n+1) {cout<<"NO"<<endl; return; }
                if(a[i]>val) break;
                i++;
            }
        }
    }

    cout<<"YES"<<endl;
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