/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n,x,m;
    cin>>n>>x>>m;
    int strt=x,nd=x;

    for(int i=1;i<=m;i++)
    {
        long long int a,b;
        cin>>a>>b;
        if(a<strt && b>=strt) strt=a;
        if(a<=nd && b>nd) nd=b;
    }

    cout<<nd-strt+1<<endl;
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