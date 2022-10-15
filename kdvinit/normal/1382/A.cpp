/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    int x,b[m+1],freq[1001]={0};
    for(int i=1;i<=n;i++) { cin>>x; freq[x]++; }
    for(int i=1;i<=m;i++) cin>>b[i];

    for(int i=1;i<=m;i++)
    {
        if(freq[b[i]]!=0) { cout<<"YES"<<endl<<1<<" "<<b[i]<<endl; return; }
    }

    cout<<"NO"<<endl;
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