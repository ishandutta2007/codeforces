#include <iostream>

using namespace std;

int n,a[100100],b,ans;

int main()
{
    cin>>n;
    b=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==i)
            ans++;
        if(a[i]<i)
            if(a[a[i]]==i)
                b=2;
    }
    if(ans==n)
        cout<<ans<<endl;
    else
        cout<<ans+b<<endl;
}