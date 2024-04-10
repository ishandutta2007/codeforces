#include <iostream>
using namespace std;

void solve()
{
    int n,x;
    cin>>n>>x;
    int odd=0,even=0,v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        if(v%2==0) even++;
        else odd++;
    }
    if(odd==0) { cout<<"No"<<endl; return; }
    if(x==n)
    {
        if(odd%2==1) { cout<<"Yes"<<endl; return; }
        else { cout<<"No"<<endl; return; }
    }
    if(even==0)
    {
        if(x%2==1) { cout<<"Yes"<<endl; return; }
        else { cout<<"No"<<endl; return; }
    }
    cout<<"Yes"<<endl;
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