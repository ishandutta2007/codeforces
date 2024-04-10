/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int freq1=0,freq0=0,cntr=0;
    int y;
    cin>>y;
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        if(x<y) cntr++;
        y=x;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==0) freq0++;
        else freq1++;
    }

    if(cntr==0) { cout<<"Yes"<<endl; return; }

    if(freq1*freq0==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
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