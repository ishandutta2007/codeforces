/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+1],pos[n+1];
    pos[1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0 || i==n) pos[i+1]=pos[i];
        if(a[i]==1)
        {
            if(pos[i]==0) pos[i+1]=1;
            if(pos[i]==1) pos[i+1]=1;
            if(pos[i]==-1 || pos[i]==2) pos[i+1]=2;
        }
        if(a[i]==-1)
        {
            if(pos[i]==0) pos[i+1]=-1;
            if(pos[i]==-1) pos[i+1]=-1;
            if(pos[i]==1 || pos[i]==2) pos[i+1]=2;
        }
    }

    int cntr=0;
    for(int i=1;i<=n;i++)
    {
        long long int x;
        cin>>x;
        if(pos[i]==0 && a[i]!=x) cntr++;
        if(pos[i]==1 && a[i]>x) cntr++;
        if(pos[i]==-1 && a[i]<x) cntr++;
    }

    if(cntr==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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