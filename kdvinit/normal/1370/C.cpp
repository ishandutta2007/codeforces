/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n;
    cin>>n;

    if(n==1) { cout<<"FastestFinger"<<endl; return; }
    if(n%2==1 || n==2) { cout<<"Ashishgup"<<endl; return; }

    int cnt=0;
    while(1)
    {
        if(n%2==1) break;
        n/=2;
        cnt++;
    }

    int prime=1;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0) { prime=0; break; }
    }

    if(n==1) { cout<<"FastestFinger"<<endl; return; }
    if(prime==1 && cnt==1) { cout<<"FastestFinger"<<endl; return; }
    else { cout<<"Ashishgup"<<endl; return; }
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