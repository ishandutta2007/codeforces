/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    char a[n+1],b[n+1];
    int c[4*n],cntr=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            int x=(i+1)/2;
            if(a[x]!=b[n+1-i]) c[++cntr]=n+1-i;
            else
            {
                c[++cntr]=1;
                c[++cntr]=n+1-i;
            }
        }
        else
        {
            int x=n+1-(i/2);
            if(a[x]==b[n+1-i]) c[++cntr]=n+1-i;
            else
            {
                c[++cntr]=1;
                c[++cntr]=n+1-i;
            }
        }
    }

    cout<<cntr<<" ";
    for(int i=1;i<=cntr;i++) cout<<c[i]<<" ";
    cout<<endl;
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