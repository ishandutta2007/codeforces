/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[2*n+1];

    for(int i=1;i<=2*n;i++) cin>>a[i];

    int cntr=0,odd=0,even=0;
    for(int i=1;i<=2*n;i++)
    {
        int x;
        x=a[i];
        if(x%2==0)
        {
            if(even==0) even=i;
            else
            {
                cout<<even<<" "<<i<<endl;
                even=0;
                cntr++;
            }
        }
        else
        {
            if(odd==0) odd=i;
            else
            {
                cout<<odd<<" "<<i<<endl;
                odd=0;
                cntr++;
            }
        }

        if(cntr==n-1) return;
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