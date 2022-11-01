#include <iostream>
#include<algorithm>

using namespace std;

long long v1,v2,n,d,ans;
int main()
{
    cin>>v1>>v2>>n>>d;
    ans=v1+v2;
    for(int i=1;i<n-1;i++)
        ans+=min(v1+d*i,v2+d*(n-i-1));
    cout<<ans<<endl;
}