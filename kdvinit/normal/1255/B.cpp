/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n,m,sum=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }

    if(n==2 || m!=n) cout<<-1<<endl;
    else
    {
        cout<<2*sum<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<i<<" "<<(i+1)<<endl;
        }
        cout<<n<<" "<<1<<endl;
    }
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