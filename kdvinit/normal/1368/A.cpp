/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int a,b,n,cntr=0;
    cin>>a>>b>>n;
    while(1)
    {
        if(max(a,b)>n) break;
        if(a<b) a=a+b;
        else b=a+b;
        cntr++;
    }

    cout<<cntr<<endl;
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