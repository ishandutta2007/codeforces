/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int c,d,a,b,n,cntr=0;
    cin>>c>>d;
    a=max(c,d);
    b=min(c,d);
    if(a%b!=0) { cout<<-1<<endl; return; }
    n=(a/b);

    while(n!=1)
    {
        if(n%2!=0) { cout<<-1<<endl; return; }
        cntr++;
        n/=2;
    }
    cout<<(cntr+2)/3<<endl;
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