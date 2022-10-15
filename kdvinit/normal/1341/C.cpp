#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<n;i++)
        {
            if(a[i]-a[i-1]>1) break;
        }
        if(i==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}