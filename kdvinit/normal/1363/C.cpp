#include <iostream>
using namespace std;

void solve()
{
    int n,x,v,d=0,k;
    cin>>n>>x;
    k=n;
    n-=1;
    n*=2;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        if(v==x) d++;
    }
    if(d==1 || d==0) { cout<<"Ayush"<<endl; return; }
    if(k%2==0) cout<<"Ayush"<<endl;
    else cout<<"Ashish"<<endl;
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