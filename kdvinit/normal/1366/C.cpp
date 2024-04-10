/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    int v=(n+m)/2;
    int a[v]={0},b[v]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y=i+j;
            cin>>x;
            if(y<v) { a[y]+=x; b[y]++; }
            else { a[n+m-2-y]+=x; b[n+m-2-y]++; }
        }
    }

    if((m+n)%2==0) v--;
    int ans=0;

    for(int i=0;i<v;i++)
    {
        //cout<<a[i]<<" ";
        ans+=min(a[i],b[i]-a[i]);
    }

    //cout<<endl;
    cout<<ans<<endl;
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