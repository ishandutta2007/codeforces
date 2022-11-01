#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>

using namespace std;

long long ans,n,b,a[200];

int main()
{
    cin>>n>>b;
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        ans=max(ans,a[i-1]-a[i]-b);
    }
    cout<<ans<<endl;
}