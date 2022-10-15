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

    int f[31]={0};
    for(int i=1;i<=n;i++)
    {
        long long int x;
        cin>>x;
        for(int j=1;j<=30;j++)
        {
            if(x==0) break;
            if(x%2==1) f[j]++;
            x/=2;
        }
    }
    for(int i=30;i>0;i--)
    {
        int x=f[i]%4;
        if(x==1) { cout<<"WIN"<<endl; return; }
        if(x==3)
        {
            if(n%2==0) { cout<<"WIN"<<endl; return; }
            else { cout<<"LOSE"<<endl; return; }
        }
    }
    cout<<"DRAW"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}