#include <iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

long long n,m,ans,d,a[200];

int main()
{
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    sort(a,a+n);
    if(m<=n)
    {
        for(int i=0;i<m;i++)
            ans+=a[i];
        cout<<ans<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
            ans+=a[i];
        ans=ans-(m-n)*d;
        cout<<ans<<endl;
    }
}