/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    string a;
    cin>>a;
    int n=a.size();
    cout<<a[0];
    for(int i=1;i<n;i++)
    {
        if(i%2==1) continue;
        else cout<<a[i];
    }
    cout<<a[n-1]<<endl;
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