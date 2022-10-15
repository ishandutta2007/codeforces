/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int odd=0,even=0,cor=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x%2==1) odd++;
        else even++;
        if(x%2==i%2) cor++;
    }

    int a=(n+1)/2;
    if(even!=a) cout<<-1<<endl;
    else cout<<(n-cor)/2<<endl;

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