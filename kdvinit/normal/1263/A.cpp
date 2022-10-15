#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int r,g,b,sum,l,x;
        cin>>r>>g>>b;
        sum=r+g+b;
        l=max(r,max(g,b));
        x=3*l-sum;
        sum/=2;
        if(x<=l) cout<<sum<<endl;
        else cout<<2*l-x<<endl;
    }
    return 0;
}