#include <iostream>

using namespace std;

int n,k,a[200],MIN=200,MAX;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        MIN=min(MIN,a[i]);
        MAX=max(MAX,a[i]);
    }
    if(MAX-MIN>k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<MIN;j++)
            cout<<"1 ";
        for(int j=MIN;j<a[i];j++)
            cout<<j-MIN+1<<" ";
        cout<<endl;
    }
}