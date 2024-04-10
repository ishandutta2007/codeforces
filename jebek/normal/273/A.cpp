#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,w,h;
long long ans,MAX,a[200000];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>w>>h;
        ans=max(a[w],MAX);
        cout<<ans<<endl;
        MAX=ans+h;
    }
}