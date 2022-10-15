/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    long long int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int m=n/2;
    if(n%2==1 && a[m]!=b[m]) { cout<<"No"<<endl; return; }

    for(int i=0;i<m;i++)
    {
        if(a[i]>a[n-1-i]) swap(a[i],a[n-1-i]);
        if(b[i]>b[n-1-i]) swap(b[i],b[n-1-i]);
    }

    int i;
    for(i=0;i<m;i++)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(a[i]==b[j] && a[n-1-i]==b[n-1-j]) { b[j]=0; break; }
        }
        if(j==m) { cout<<"No"<<endl; return; }
    }

    cout<<"Yes"<<endl;
    return;
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