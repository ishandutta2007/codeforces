/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int y=(x-1)/2;
        int z=(x+1)/2;
        if(x%2==0) cout<<(x/2)<<endl;
        else
        {
            if(cnt==0) { cout<<(x-1)/2<<endl; cnt=1; }
            else { cout<<(x+1)/2<<endl; cnt=0; }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--) solve();
	return 0;
}