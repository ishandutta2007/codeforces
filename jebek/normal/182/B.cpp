#include <iostream>

using namespace std;

long long n,k,a,ans;

int main()
{
    cin>>k>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        ans+=k-a;
    }
    cin>>a;
    cout<<ans<<endl;
}