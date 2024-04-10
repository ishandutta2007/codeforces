/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

int mex(int a[],int n)
{
    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    sort(b,b+n);
    if(b[0]!=0) return 0;
    for(int i=1;i<n;i++)
    {
        if(b[i]-b[i-1]>1) return b[i-1]+1;
    }
    return b[n-1]+1;
}

void solve()
{
    int n;
    cin>>n;

    int a[n],ans[2*n+1],cntr=0;
    for(int i=0;i<n;i++) cin>>a[i];

    while(1)
    {
        int x=mex(a,n);
        if(x<n)
        {
            ans[++cntr]=x+1;
            a[x]=x;
        }
        else
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(a[j]!=j) break;
            }
            if(j==n) break;
            ans[++cntr]=j+1;
            a[j]=n;
        }
    }

    cout<<cntr<<endl;
    for(int i=1;i<=cntr;i++) cout<<ans[i]<<" ";
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