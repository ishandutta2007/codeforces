#include <iostream>
#include<algorithm>

using namespace std;

int n,a[200000],m;

int main()
{
    cin>>n;
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        int k=lower_bound(a,a+n,x)-a;
        cout<<k+1<<endl;
    }
}