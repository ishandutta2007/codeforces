/*
KDVINIT

My Test Case -

Mistakes -

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,sum,ans;
        cin>>n;
        ans=n*n*((n-1)/2);
        n-=2;
        sum=(n*(n+1)*(2*n+1))/6;
        n=(n-1)/2;
        sum=sum-(2*n*(n+1)*(2*n+1))/3;
        ans-=sum;
        cout<<ans<<endl;
    }
    return 0;
}