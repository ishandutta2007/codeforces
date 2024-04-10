/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int freq[n+1]={0};
    for(int i=1;i<=2*n;i++)
    {
        int x;
        cin>>x;
        if(freq[x]==0) { freq[x]=1; cout<<x<<" ";}
    }
    cout<<endl;
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