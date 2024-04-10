/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int l,r,m,d;
    cin>>l>>r>>m;
    d=r-l;

    for(int i=l;i<=r;i++)
    {
        long long int x=m%i;
        if(x<=d && m!=x)
        {
            cout<<i<<" "<<l+x<<" "<<l<<endl;
            return;
        }
        x=i-x;
        if(x<=d)
        {
            cout<<i<<" "<<l<<" "<<l+x<<endl;
            return;
        }
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}